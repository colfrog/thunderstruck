#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Direction.h"
#include "Element.h"
#include "Enemy.h"
#include <vector>
#include <random>

using namespace std;

class Lane : public Element
{
public:
	Lane(Direction dir = Direction::UP);
	~Lane();
	
	int get_laneId();
	int get_distance();
	int get_nbEnnemi();
	Direction get_direction();

	void set_laneId(int laneId);
	void set_distance(int distance);
	void set_nbEnnemi(int nbEnnemi);

	bool all_dead();

	Enemy changer_typeEnemy(string name, int drop);
	Enemy changer_typeEnemy(string name, int drop, Weapon weapon, Defense defense);

	virtual void step();

private:
	const Direction m_dir;
	int m_laneId;
	int m_distance;
	int m_total_nbEnemy;
	int m_actual_nbEnemy;
	vector<Enemy> m_list_enemy;
};
