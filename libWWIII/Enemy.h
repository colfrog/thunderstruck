#pragma once

#include "Personnage.h"

class Lane;

class Enemy : public Personnage
{
public:
	Enemy(const Jeu *jeu, const Lane *lane, string n = "");
	~Enemy();

	int get_drop();
	void set_drop(int dr);

	void levelUp();

	virtual void step();

private:
	int m_drop;
	const Lane *m_lane;
};
