#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Lane : public Element
{
public:
	Lane();
	~Lane();

	int get_laneId();
	int get_distance();
	int get_nbEnnemi();

	void set_laneId(int laneId);
	void set_distance(int distance);
	void set_nbEnnemi(int nbEnnemi);

	virtual void step();

private:
	int m_laneId;
	int m_distance;
	int m_nbEnnemi;
};
