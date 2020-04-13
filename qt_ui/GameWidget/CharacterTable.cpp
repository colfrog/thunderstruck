#include "CharacterTable.h"

class NumericalItem : public QTableWidgetItem {
public:
	virtual bool operator<(const QTableWidgetItem &other) const {
		return text().toInt() < other.text().toInt();
	}
};

CharacterTable::CharacterTable(Jeu *jeu) : GameObject(jeu) {
	m_table = new QTableWidget(0, 7);
	list<QString> informations = { "Nom","Id","Vie", "Attaque", "Defense", "Position", "Distance" };

	int i = 0;
	for (const QString &info : informations) {
		m_table->setHorizontalHeaderItem(i, new QTableWidgetItem(info));
		i++;
	}

	const Personnage *player = &jeu->tour().player();
	m_player_coord = player->position();
	gameUpdate();
}
CharacterTable::~CharacterTable() {
	delete m_table;
}

QWidget *CharacterTable::widget() {
	return m_table;
}

int CharacterTable::getCharacterRow(const Personnage *p) const {
	QString id = QString::number(p->get_id());
	int rowCount = m_table->rowCount();
	QTableWidgetItem *item = NULL;

	for (int i = 0; i < rowCount; i++) {
		item = m_table->item(i, 1);
		if (item != NULL && id == item->text())
			return i;
	}

	return -1;
}

void CharacterTable::addCharacter(const Personnage *p) {
	int row = m_table->rowCount();
	m_table->setRowCount(row + 1);

	m_table->setVerticalHeaderItem(row, new QTableWidgetItem());

	for (int i = 0; i < 7; i++) {
		if (i == 0 || i == 5)
			m_table->setItem(row, i, new QTableWidgetItem());
		else
			m_table->setItem(row, i, new NumericalItem());
	}

	m_alive.push_back(p);
	updateCharacter(p, row);
}

void CharacterTable::removeDeadCharacters() {
	std::list<const Personnage *> dead;
	std::list<const Personnage *>::iterator it = m_alive.begin();

	while (it != m_alive.end()) {
		if ((*it)->get_hp() == 0)
			dead.push_back(*it);

		it++;
	}

	for (std::list<const Personnage *>::iterator it = dead.begin(); it != dead.end(); it++) {
		int index = 0;
		while (index < m_table->rowCount()) {
			if (m_table->item(index, 1)->text().toInt() == (*it)->get_id()) {
				m_table->removeRow(index);
				index = m_table->rowCount();
			}
			index++;
		}

		m_alive.remove(*it);
	}
}

void CharacterTable::updateCharacter(const Personnage *p, int row) {
	if (row == -1)
		row = getCharacterRow(p);
	if (row == -1)
		return;

	QString itemName;
	if (p->get_id() == 0)
		itemName = "Joueur";
	else if (p->get_id() == 1)
		itemName = "Vendeur";	
	else
		itemName = "Ennemi";

	m_table->verticalHeaderItem(row)->setText(itemName);

	m_table->item(row, 0)->setText(QString::fromStdString(p->get_name()));

	uint64_t items[] = {
		p->get_id(),
		p->get_hp(),
		(uint64_t) p->get_weapon().get_attack(),
		(uint64_t) p->get_defense().get_armure()
	};
	for (int i = 1; i < 5; i++)
		m_table->item(row, i)->setText(QString::number(items[i - 1]));

	if (p->get_id() == 0) {
		m_table->item(row, 5)->setText("Tour");
		m_table->item(row, 6)->setText("0");
		return;
	}

	if (p->get_id() == 1) {
		m_table->item(row, 5)->setText("Magasin");
		m_table->item(row, 6)->setText("1");
		return;
	}

	QString dir;
	// On attaque dans la direction opposée de leur direction
	// (Ils marchent vers nous)
	switch (p->direction()) {
	case Direction::UP:
		dir = "Sud";
		break;
	case Direction::DOWN:
		dir = "Nord";
		break;
	case Direction::LEFT:
		dir = "Est";
		break;
	case Direction::RIGHT:
		dir = "Ouest";
		break;
	}

	QString dist = QString::number(p->position().distance(m_player_coord));
	m_table->item(row, 5)->setText(dir);
	m_table->item(row, 6)->setText(dist);
}

void CharacterTable::gameUpdate() {
	removeDeadCharacters();

	for (const Personnage *p : jeu->newly_spawned())
		addCharacter(p);
	// Clear so that we can call gameUpdate multiple times per step
	jeu->newly_spawned().clear();

	for (const Personnage *p : m_alive)
		updateCharacter(p);

	// Sort by distance
	m_table->sortItems(6, Qt::AscendingOrder);
}
