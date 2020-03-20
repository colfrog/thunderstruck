#pragma once

#include <iostream>
#include <string>
#include "Element.h"
#include "Player.h"

using namespace std;

class Tour : public Element {
public:
	Tour(Jeu *jeu, std::string player_name = "");
	~Tour();

	/* dommage retourne les dégâts pris */
	int damage(const Weapon &w, int mod = 0);

	Player player();
	unsigned int hp();

	void set_hp(unsigned int hp);
	void set_player(Player player);

	//La fonction retourne 0 si la tour est upgradee et -1 si la tour n'est pas upgradee
	int upgrade_tour();
	//La fonction retourne 0 si la tour est reparee et -1 si la tour n'est pas reparee
	int reparer_tour();

	virtual void step();
	virtual void show() const;

private:
	unsigned int m_hp = 10;
	unsigned int m_total_hp = 10;
	Player m_player;
};
