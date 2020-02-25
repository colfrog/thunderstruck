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

	Player get_player();

	void set_player(Player player);

	virtual void step();

private:
	Player m_player;
};
