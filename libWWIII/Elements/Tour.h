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

	Player player();
	unsigned int hp();

	void set_hp(unsigned int hp);
	void set_player(Player player);

	//La fonction retourne le montant payé si la tour est upgradee et -1 si la tour n'est pas upgradee
	int upgrade_tour(int argent);
	//La fonction retourne le montant payé si la tour est reparee et -1 si la tour n'est pas reparee
	int reparer_tour(int argent);

	virtual void step();
	virtual void show() const;

	virtual int attack(Element &elem, int mod = 0);
	virtual int damage(const Weapon &w, int mod = 0);

private:
	unsigned int m_hp = 10;
	unsigned int m_total_hp = 10;
	Player m_player;
};
