#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Direction.h"
#include "Element.h"

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

	virtual void step();

private:
	const Direction m_dir;
	int m_laneId;
	int m_distance;
	int m_nbEnnemi;
};
