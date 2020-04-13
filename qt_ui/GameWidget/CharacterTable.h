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
	int getCharacterRow(const Personnage *p) const;
	void addCharacter(const Personnage *p);
	void removeDeadCharacters();
	void updateCharacter(const Personnage *p, int row = -1);

	QTableWidget *m_table;
	list<const Personnage *> m_alive;
	Coord m_player_coord;
};
