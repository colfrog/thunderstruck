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

	uint64_t get_id() const;

	string get_name() const;
	void set_name(string n);

	unsigned long get_hp() const;
	void set_hp(unsigned long hp);

	Defense get_defense() const;
	void set_defense(Defense def);

	Weapon get_weapon() const;
	void set_weapon(Weapon w);

	bool is_dead() const;

	Direction direction() const;
	void set_direction(Direction dir);
	void turn_left();
	void turn_right();

	virtual void step() {};
	void show() const;

	virtual int attack(Element &elem, int mod = 0);
	virtual int damage(const Weapon &w, int mod = 0);

protected:
	uint64_t m_id;
	string m_name = "";
	unsigned long m_hp = 100;
	Defense m_defense;
	Weapon m_weapon;
	Direction m_dir = Direction::UP;
};
