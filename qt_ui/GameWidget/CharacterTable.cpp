#include "CharacterTable.h"

CharacterTable::CharacterTable(Jeu *jeu) : QTableWidget(), GameObject(jeu){
	insertRow(1);
	insertColumn(6);

	QLable *title = new QLabel();

	title.setText("Nom");
	setHorizontalHeaderLabels(0, title);
	title.setText("Vie");
	setHorizontalHeaderLabels(1, title);
	title.setText("Attaque");
	setHorizontalHeaderLabels(2, title);
	title.setText("Defense");
	setHorizontalHeaderLabels(3, title);
	title.setText("Position");
	setHorizontalHeaderLabels(4, title);
	title.setText("Distance");
	setHorizontalHeaderLabels(5, title);

	title.setText("Joueur");
	m_table_potion->setVerticalHeaderLabels(0, title);

	m_list_alive.push_front(jeu->tour().player());

	setItem(0, 0, *QTableWidgetItem(QString::fromStdString(m_list_alive.front().get_name())));
	setItem(0, 1, *QTableWidgetItem(QString::fromStdString(m_list_alive.front().get_hp())));
	setItem(0, 2, *QTableWidgetItem(QString::fromStdString(m_list_alive.front().get_weapon().get_attack())));
	setItem(0, 3, *QTableWidgetItem(QString::fromStdString(m_list_alive.front().get_defense().get_armure())));
	setItem(0, 4, *QTableWidgetItem(QString::fromStdString("Tour")));
	setItem(0, 5, *QTableWidgetItem(QString::fromStdString("0")));
}
CharacterTable::~CharacterTable() {
	delete m_table;
	m_list_alive.clear();
	m_list_dead.clear();
}

void CharacterTable::gameUpdate(Jeu jeu) {
	for (list<Personnage *>::iterator it = jeu.newly_spawned().begin(); it != jeu.newly_spawned().end(); it++) {
		m_list_alive.push_back(*it);
	}
	for (list<Personnage *>::iterator it = jeu.newly_dead().begin(); it != jeu.newly_dead().end(); it++) {
		m_list_dead.push_back(*it);
	}
	
	setRowCount(m_list_alive.size());
	
	for (list<Personnage *>::iterator it = m_list_alive.front().begin(); it != m_list_alive.end(); it++) {
		setItem(index, 0, *QTableWidgetItem(QString::fromStdString(it->get_name())));
		setItem(index, 1, *QTableWidgetItem(QString::fromStdString(it->get_hp())));
		setItem(index, 2, *QTableWidgetItem(QString::fromStdString(it->get_weapon().get_attack())));
		setItem(index, 3, *QTableWidgetItem(QString::fromStdString(it->get_defense().get_armure())));
		
		if (index == 0 && !jeu.tour().player().is_dead()) {
			title.setText("Joueur");
			m_table_potion->setVerticalHeaderLabels(index, title);

			setItem(index, 4, *QTableWidgetItem(QString::fromStdString("Tour")));
			setItem(index, 5, *QTableWidgetItem(QString::fromStdString("0")));
		}
		else {
			title.setText("Ennemi");
			m_table_potion->setVerticalHeaderLabels(index, title);

			setItem(index, 4, *QTableWidgetItem(QString::fromStdString(it->direction()));
			setItem(index, 5, *QTableWidgetItem(QString::fromStdString(it->position().distance();)));
		}
	}
}