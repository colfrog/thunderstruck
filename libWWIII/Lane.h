#pragma once

#include <iostream>
#include <list>
#include <string>
#include <iomanip>

#include "Direction.h"
#include "Element.h"
#include "Enemy.h"

using namespace std;

class Lane : public Element
{
public:
	Lane(Jeu *jeu, Direction dir = Direction::UP);
	~Lane();

	bool is_empty(const Coord &position);
	bool reached_end(const Enemy *e);
	void remove_top_enemy();
	bool can_spawn();
	void spawn();

	void set_lane_id(int lane_id);
	void set_distance(int distance);

	Direction get_direction();
	Coord get_end_position();
	int get_lane_id();
	int get_distance();
	int get_enemy_count();

	Enemy make_enemy(string name, int drop);
	Enemy make_enemy(string name, int drop, Weapon weapon, Defense defense);

	virtual void step();

private:
	const Direction m_dir;
	Coord end_position;
	int m_lane_id = 0;
	int m_distance = 100;
	list<Enemy> m_enemies;
};
