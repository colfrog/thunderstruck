#pragma once

#include "Personnage.h"
class Enemy : public Personnage
{
public:
	Enemy();
	Enemy(string n);
	~Enemy();

	string getName();
	void setName(string n);

	int getDrop();
	void setDrop(int dr);

private:
	string name;
	int drop;

};