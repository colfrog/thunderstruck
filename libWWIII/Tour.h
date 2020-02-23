#pragma once

#include <iostream>
#include <string>
#include "Element.h"
#include "Player.h"

using namespace std;

class Tour : public Element {
public:
	Tour();
	~Tour();

	Player get_player();

	void set_player(Player player);

	void step();

private:
	Player m_player;
};