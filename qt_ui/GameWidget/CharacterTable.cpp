#include "CharacterTable.h"

CharacterTable::CharacterTable(Jeu *jeu) : /*QTableWidget(), */GameObject(jeu) {
	m_table = new QTableWidget(1, 6);

	m_table->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Nom")));
	m_table->setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Vie")));
	m_table->setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Attaque")));
	m_table->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Defense")));
	m_table->setHorizontalHeaderItem(4, new QTableWidgetItem(QString("Position")));
	m_table->setHorizontalHeaderItem(5, new QTableWidgetItem(QString("Distance")));

	m_table->setVerticalHeaderItem(0, new QTableWidgetItem(QString("Joueur")));

	m_list_alive.push_front(&jeu->tour().player());
	m_player_coord = m_list_alive.front()->position();

	m_table->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(m_list_alive.front()->get_name())));
	m_table->setItem(0, 1, new QTableWidgetItem(QString::number(m_list_alive.front()->get_hp())));
	m_table->setItem(0, 2, new QTableWidgetItem(QString::number(m_list_alive.front()->get_weapon().get_attack())));
	m_table->setItem(0, 3, new QTableWidgetItem(QString::number(m_list_alive.front()->get_defense().get_armure())));
	m_table->setItem(0, 4, new QTableWidgetItem(QString("Tour")));
	m_table->setItem(0, 5, new QTableWidgetItem(QString("0")));
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
	for (Personnage *p : m_list_alive) {
		m_list_alive.push_back(p);
	}
	for (Personnage *p : m_list_alive) {
		m_list_dead.push_back(p);
	}

	m_table->setRowCount((int)m_list_alive.size());

	int index = 0;
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
	}

	m_table->sortItems(5, Qt::AscendingOrder);
}