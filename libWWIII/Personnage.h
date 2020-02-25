#pragma once
#include "Direction.h"
#include "Defense.h"
#include "Weapon.h"
#include "Element.h"

class Personnage : public Element
{
public:
	Personnage(const Jeu *jeu, string n);
	~Personnage();

	string get_name();
	void set_name(string n);

	unsigned long get_hp();
	void set_hp(unsigned long hp);

	Defense get_defense();
	void set_defense(Defense def);
	
	Weapon get_weapon();
	void set_weapon(Weapon w);

	Direction direction();
	void turn_left();
	void turn_right();

	virtual void step() {};

protected:
	string m_name = "";
	unsigned long m_hp = 100;
	Defense m_defense;
	Weapon m_weapon;
	Direction m_dir = Direction::UP;
};
