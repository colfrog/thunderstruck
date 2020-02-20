#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	~Weapon();
	
	long get_attack();
	long get_frequence();

	void set_attack(long attack);
	void set_frequence(long frequence);

	void afficher();
private:
	long m_attack;
	long m_frequence;
};

