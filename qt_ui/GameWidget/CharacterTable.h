#pragma once

#include <QTableWidget>
#include <list>
#include "GameObject.h"

class CharacterTable : public GameObject, public QTableWidget {
public:
	CharacterTable(Jeu *jeu);
	~CharacterTable();

public slots:
	void gameUpdate(Jeu jeu);
protected:
	list<Personnage *> m_list_alive;
	list<Personnage *> m_list_dead;
};