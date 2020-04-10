#include "CharacterTable.h"

CharacterTable::CharacterTable(Jeu *jeu) : /*QTableWidget(), */GameObject(jeu) {
	m_table = new QTableWidget(1, 7);
	list<QString> informations = { "Id","Nom","Vie", "Attaque", "Defense", "Position", "Distance" };

	int index = 0;
	for (QString info : informations) {
		m_table->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}
	
	m_table->setVerticalHeaderItem(0, new QTableWidgetItem(QString("Joueur")));

	m_list_alive.push_front(&jeu->tour().player());
	m_player_coord = m_list_alive.front()->position();

	m_table->setItem(0, 0, new QTableWidgetItem(QString::number(m_list_alive.front()->get_id())));
	m_table->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(m_list_alive.front()->get_name())));
	m_table->setItem(0, 2, new QTableWidgetItem(QString::number(m_list_alive.front()->get_hp())));
	m_table->setItem(0, 3, new QTableWidgetItem(QString::number(m_list_alive.front()->get_weapon().get_attack())));
	m_table->setItem(0, 4, new QTableWidgetItem(QString::number(m_list_alive.front()->get_defense().get_armure())));
	m_table->setItem(0, 5, new QTableWidgetItem(QString("Tour")));
	m_table->setItem(0, 6, new QTableWidgetItem(QString("0")));
}
CharacterTable::~CharacterTable() {
	delete m_table;
	m_list_alive.clear();
	m_list_dead.clear();
}

QWidget *CharacterTable::widget() {
	return m_table;
}

void CharacterTable::gameUpdate() {
	for (Personnage *p : jeu->newly_spawned()) {
		m_list_alive.push_back(p);
		m_table->setRowCount(m_table->rowCount() + 1);

		m_table->setVerticalHeaderItem(m_table->rowCount() - 1, new QTableWidgetItem(QString("Ennemi")));

		m_table->setItem(m_table->rowCount() - 1, 0, new QTableWidgetItem(QString::number(p->get_id())));
		m_table->setItem(m_table->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(p->get_name())));
		m_table->setItem(m_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(p->get_hp())));
		m_table->setItem(m_table->rowCount() - 1, 3, new QTableWidgetItem(QString::number(p->get_weapon().get_attack())));
		m_table->setItem(m_table->rowCount() - 1, 4, new QTableWidgetItem(QString::number(p->get_defense().get_armure())));

		switch (p->direction()) {
		case Direction::UP:
			m_table->setItem(m_table->rowCount() - 1, 5, new QTableWidgetItem(QString("North")));
			break;
		case Direction::DOWN:
			m_table->setItem(m_table->rowCount() - 1, 5, new QTableWidgetItem(QString("South")));
			break;
		case Direction::LEFT:
			m_table->setItem(m_table->rowCount() - 1, 5, new QTableWidgetItem(QString("West")));
			break;
		case Direction::RIGHT:
			m_table->setItem(m_table->rowCount() - 1, 5, new QTableWidgetItem(QString("East")));
			break;
		}

		m_table->setItem(m_table->rowCount() - 1, 6, new QTableWidgetItem(QString::number(p->position().distance(m_player_coord))));
	}

	for (Personnage *p : jeu->newly_dead()) {

		QTableWidgetItem *id_perso = new QTableWidgetItem(QString::number(p->get_id()));
		list<Personnage *>::iterator it = m_list_alive.begin();
		bool list_finish = false, table_finish = false;

		for (int index = 0; index < m_table->rowCount(); index++) {
			if (id_perso == m_table->item(index, 0)) {
				m_table->removeRow(index);
				index = m_table->rowCount();
				table_finish = true;
			}

			if (it == m_list_alive.end()) {
				list_finish = true;
			}
			else if (*it == p) {
				m_list_alive.erase(it);
			}
			
			if (table_finish == true && list_finish == true) {
				break;
			}
		}

		m_list_dead.push_back(p);
	}

	/*int index = 0;
	for (Personnage *p : m_list_alive) {
		m_table->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(p->get_name())));
		m_table->setItem(index, 1, new QTableWidgetItem(QString::number(p->get_hp())));
		m_table->setItem(index, 2, new QTableWidgetItem(QString::number(p->get_weapon().get_attack())));
		m_table->setItem(index, 3, new QTableWidgetItem(QString::number(p->get_defense().get_armure())));

		if (index == 0 && !jeu->tour().player().is_dead()) {
			m_table->setVerticalHeaderItem(index, new QTableWidgetItem(QString("Joueur")));

			m_table->setItem(index, 4, new QTableWidgetItem(QString("Tour")));
			m_table->setItem(index, 5, new QTableWidgetItem(QString("0")));
		}
		else {
			m_table->setVerticalHeaderItem(index, new QTableWidgetItem(QString("Ennemi")));

			if (p->direction() == Direction::UP) {
				m_table->setItem(index, 4, new QTableWidgetItem(QString("North")));
			}
			else if (p->direction() == Direction::DOWN) {
				m_table->setItem(index, 4, new QTableWidgetItem(QString("South")));
			}
			else if (p->direction() == Direction::LEFT) {
				m_table->setItem(index, 4, new QTableWidgetItem(QString("West")));
			}
			else if (p->direction() == Direction::RIGHT) {
				m_table->setItem(index, 4, new QTableWidgetItem(QString("East")));
			}
			m_table->setItem(index, 5, new QTableWidgetItem(QString::number(p->position().distance(m_player_coord))));
		}

		index++;
	}*/

	m_table->sortItems(5, Qt::AscendingOrder);
}