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

	string getName();
	void setName(string n);

	int getArgent();
	void setArgent(int arg);

private:
	Stats stats;
	string name;
	int argent;
};