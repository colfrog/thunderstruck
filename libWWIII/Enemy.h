#pragma once

#include "Personnage.h"

class Lane;

class Enemy : public Personnage
{
public:
	Enemy(Jeu *jeu, Lane *lane, string n = "");
	~Enemy();

	int get_drop();
	void set_drop(int dr);

	virtual void step();

private:
	int m_drop;
	Lane *m_lane;
};
