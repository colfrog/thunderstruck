#pragma once

#include "Item.h"

class Potion : public Item {
public:
	Potion();
	~Potion();

	long get_hp_restore();
	void set_hp_restore(long hp);
	void afficher();
private:
	long m_hp_restore;
};


