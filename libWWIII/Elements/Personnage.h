#pragma once
#include "Element.h"
#include "../Direction.h"
#include "../Items/Defense.h"
#include "../Items/Weapon.h"

class Personnage : public Element
{
public:
	Personnage(Jeu *jeu, string n);
	~Personnage();

	/* dommage retourne les dégâts pris */
	int damage(const Weapon &w, int mod = 0);

	string get_name();
	void set_name(string n);

	unsigned long get_hp();
	void set_hp(unsigned long hp);

	Defense get_defense();
	void set_defense(Defense def);
	
	Weapon get_weapon();
	void set_weapon(Weapon w);

	Direction direction();
	void set_direction(Direction dir);
	void turn_left();
	void turn_right();

	virtual void step() {};
	void show() const;

protected:
	string m_name = "";
	unsigned long m_hp = 100;
	Defense m_defense;
	Weapon m_weapon;
	Direction m_dir = Direction::UP;
};
