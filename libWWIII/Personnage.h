#pragma once
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


private:
	string name;
	unsigned long hp;
	Defense defense;
	Weapon weapon;
};