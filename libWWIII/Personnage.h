#pragma once
#include "Defense.h"
#include "Weapon.h"
#include "Element.h"

class Personnage : public Element
{
public:
	Personnage();
	~Personnage();

	unsigned long getHp();
	void setHP(unsigned long HP);

	Defense getDefense();
	void setDefense(Defense def);
	
	Weapon getWeapon();
	void setWeapon(Weapon w);


private:
	unsigned long hp;
	Defense defense;
	Weapon weapon;
};