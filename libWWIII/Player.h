#pragma once

#include "Stats.h"
#include "Personnage.h"
#include "Shop.h"

class Player : public Personnage
{
public:
	Player(Jeu *jeu, string n = "");
	~Player();

	Stats get_stats();
	void set_stats(Stats st);

	int get_argent();
	void set_argent(int arg);

	Shop get_shop();
	void set_shop(Shop s);

	// Méthode pour entrer dans le magasin
	void enter_shop();

	virtual void step();
private:
	Stats m_stats;
	int m_argent = 0;
	int m_hp_regen = 0;
	
	Shop m_shop;
};
