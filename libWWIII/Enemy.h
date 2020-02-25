#pragma once

#include "Personnage.h"
class Enemy : public Personnage
{
public:
	Enemy();
	Enemy(string n);
	~Enemy();

	int get_drop();
	void set_drop(int dr);

	virtual void step();

private:
	int m_drop;

};
