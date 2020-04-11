#pragma once

#include <QTableWidget>
#include <QString>
#include <list>
#include "GameObject.h"

class CharacterTable : public GameObject {
	Q_OBJECT
public:
	CharacterTable(Jeu *jeu);
	~CharacterTable();

	QWidget *widget();

public slots:
	virtual void gameUpdate();
protected:
	QTableWidget *m_table;
	list<const Personnage *> m_list_alive;
	list<const Personnage *> m_list_dead;
	Coord m_player_coord;
};
