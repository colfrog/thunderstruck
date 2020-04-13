#pragma once

#include <iostream>
#include <list>
#include <string>
#include <iomanip>

#include "../Direction.h"
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
	void remove_front_enemy();
	bool can_spawn();
	void spawn();

	void set_lane_id(int lane_id);
	void set_distance(int distance);

	Direction get_direction() const;
	Coord get_end_position() const;
	int get_lane_id() const;
	int get_distance() const;
	int get_enemy_count() const;

	Enemy *make_enemy(string name, int drop);
	Enemy *make_enemy(string name, int drop, Weapon weapon, Defense defense);

	virtual void step();
	virtual void show() const;

	virtual int attack(Element &elem, int mod = 0);
	virtual int damage(const Weapon &w, int mod = 0);

private:
	const Direction m_dir;
	int m_lane_id = 0;
	int m_distance = 10;
	list<Enemy *> m_enemies;
};
