#include "CharacterTable.h"

CharacterTable::CharacterTable(Jeu *jeu) : QTableWidget(), GameObject(jeu){
	setRowCount(1);
	setColumnCount(6);

	setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Nom")));
	setHorizontalHeaderItem(1, new QTableWidgetItem(QString("Vie")));
	setHorizontalHeaderItem(2, new QTableWidgetItem(QString("Attaque")));
	setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Defense")));
	setHorizontalHeaderItem(4, new QTableWidgetItem(QString("Position")));
	setHorizontalHeaderItem(5, new QTableWidgetItem(QString("Distance")));

	setVerticalHeaderItem(0, new QTableWidgetItem(QString("Joueur")));

	m_list_alive.push_front(&jeu->tour().player());
	m_player_coord = m_list_alive.front()->position();

	setItem(0, 0, new QTableWidgetItem(QString::fromStdString(m_list_alive.front()->get_name())));
	setItem(0, 1, new QTableWidgetItem(QString::number(m_list_alive.front()->get_hp())));
	setItem(0, 2, new QTableWidgetItem(QString::number(m_list_alive.front()->get_weapon().get_attack())));
	setItem(0, 3, new QTableWidgetItem(QString::number(m_list_alive.front()->get_defense().get_armure())));
	setItem(0, 4, new QTableWidgetItem(QString("Tour")));
	setItem(0, 5, new QTableWidgetItem(QString("0")));

	
}
CharacterTable::~CharacterTable() {
	m_list_alive.clear();
	m_list_dead.clear();
}

void CharacterTable::gameUpdate() {}
void CharacterTable::gameUpdate(Jeu jeu) {
	for (Personnage *p : m_list_alive) {
		m_list_alive.push_back(p);
	}
	for (Personnage *p : m_list_alive) {
		m_list_dead.push_back(p);
	}
	
	setRowCount((int)m_list_alive.size());

	int index = 0;
	for (Personnage *p : m_list_alive) {
		setItem(index, 0, new QTableWidgetItem(QString::fromStdString(p->get_name())));
		setItem(index, 1, new QTableWidgetItem(QString::number(p->get_hp())));
		setItem(index, 2, new QTableWidgetItem(QString::number(p->get_weapon().get_attack())));
		setItem(index, 3, new QTableWidgetItem(QString::number(p->get_defense().get_armure())));
		
		if (index == 0 && !jeu.tour().player().is_dead()) {
			setVerticalHeaderItem(index, new QTableWidgetItem(QString("Joueur")));

			setItem(index, 4, new QTableWidgetItem(QString("Tour")));
			setItem(index, 5, new QTableWidgetItem(QString("0")));
		}
		else {
			setVerticalHeaderItem(index, new QTableWidgetItem(QString("Ennemi")));

			if (p->direction() == Direction::UP) {
				setItem(index, 4, new QTableWidgetItem(QString("North")));
			}
			else if (p->direction() == Direction::DOWN) {
				setItem(index, 4, new QTableWidgetItem(QString("South")));
			}
			else if (p->direction() == Direction::LEFT) {
				setItem(index, 4, new QTableWidgetItem(QString("West")));
			}
			else if(p->direction() == Direction::RIGHT) {
				setItem(index, 4, new QTableWidgetItem(QString("East")));
			}
			setItem(index, 5, new QTableWidgetItem(QString::number(p->position().distance(m_player_coord))));
		}

		index++;
	}
	sortItems(5, Qt::AscendingOrder);
}