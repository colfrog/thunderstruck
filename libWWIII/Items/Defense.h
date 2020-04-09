#pragma once

#include "Item.h"

class Defense : public Item
{
public:
	Defense();
	~Defense();
	
	float get_evasion() const;
	int  get_armure() const;

	void set_evasion(int evasion);
	void set_armure(int armure);

	void afficher();
private:
	float m_evasion;
	int m_armure;
};
