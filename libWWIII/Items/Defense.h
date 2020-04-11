#pragma once

#include "Item.h"

class Defense : public Item
{
public:
	Defense();
	~Defense();
	
	int get_evasion() const;
	int  get_armure() const;

	void set_evasion(int evasion);
	void set_armure(int armure);

	void afficher();
private:
	int m_evasion;
	int m_armure;
};
