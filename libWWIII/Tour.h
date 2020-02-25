#pragma once

#include <iostream>
#include <string>
#include "Element.h"
#include "Player.h"

using namespace std;

class Tour : public Element {
public:
	Tour(const Jeu *jeu, std::string player_name = "");
	~Tour();

	/* dommage retourne les dégâts pris */
	int dommage(const Weapon &w);

	Player player();
	unsigned int hp();

	void set_hp(unsigned int hp);
	void set_player(Player player);

	virtual void step();

private:
	unsigned int m_hp;
	Player m_player;
};
