#pragma once
#include "Direction.h"
#include "Defense.h"
#include "Weapon.h"
#include "Element.h"

class Personnage : public Element
{
public:
	Personnage();
	Personnage(string n);
	~Personnage();

	string getName();
	void setName(string n);

	unsigned long getHp();
	void setHP(unsigned long HP);

	Defense getDefense();
	void setDefense(Defense def);
	
	Weapon getWeapon();
	void setWeapon(Weapon w);

	Direction direction();
	void turn_left();
	void turn_right();

	virtual void step() {};

private:
	string name;
	unsigned long hp;
	Defense defense;
	Weapon weapon;
	Direction dir;
};
