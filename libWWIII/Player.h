#pragma once

#include "Stats.h"
#include "Personnage.h"
class Player : public Personnage
{
public:
	Player();
	Player(string n);
	~Player();

	Stats getStats();
	void setStats(Stats st);

	int getArgent();
	void setArgent(int arg);

	virtual void step();
private:
	Stats stats;
	int argent;
	int hp_regen;
};
