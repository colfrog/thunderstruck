#pragma once

#include "Personnage.h"
class Enemy : public Personnage
{
public:
	Enemy();
	Enemy(string n);
	~Enemy();

	int getDrop();
	void setDrop(int dr);

	void levelUp();

	virtual void step();

private:
	int drop;

};
