#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	~Weapon();
	
	long get_attack();
	long get_frequence();
	long get_upgrade_attack();
	long get_upgrade_frequence();

	void set_attack(long attack);
	void set_frequence(long frequence);
	void set_upgrade_attack(long upgrade);
	void set_upgrade_frequence(long upgrade);

	void upgrade_weapon();

	void afficher();
private:
	long m_attack;
	long m_frequence;
	long m_upgrade_attack;
	long m_upgrade_frequence;
};

