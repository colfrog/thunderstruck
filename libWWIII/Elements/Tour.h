#pragma once

#include <iostream>
#include <string>
#include "Element.h"
#include "Player.h"

using namespace std;

class Tour : public Element {
public:
	Tour(Jeu *jeu);
	~Tour();

	Player &player();
	const unsigned int &hp() const;
	const unsigned int &radius() const;

	void set_hp(unsigned int hp);
	void set_player(Player *player);

	virtual void step();
	virtual void show() const;

	virtual int attack(Element &elem, int mod = 0);
	virtual int damage(const Weapon &w, int mod = 0);

private:
	unsigned int m_hp = 1000;
	unsigned int m_radius = 250;
	Player *m_player;
};
