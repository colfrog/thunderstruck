#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	~Weapon();
	
	int get_attack() const;
	long get_frequence() const;
	int get_upgrade_attack() const;
	long get_upgrade_frequence() const;

	void set_attack(int attack);
	void set_frequence(long frequence);
	void set_upgrade_attack(int upgrade);
	void set_upgrade_frequence(long upgrade);

	void upgrade_weapon();

	void afficher();
private:
	int m_attack;
	long m_frequence;
	int m_upgrade_attack;
	long m_upgrade_frequence;
};

