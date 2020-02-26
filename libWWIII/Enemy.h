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
	void set_next_enemy(Enemy *next_enemy);

	virtual void step();

private:
	int m_drop = 0;
	Lane *m_lane = nullptr;
	Enemy *m_next_enemy = nullptr;
};
