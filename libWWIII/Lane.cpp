#include "Lane.h"

Lane::Lane()
{
	m_laneId = 0;
	m_distance = 100;
	m_nbEnnemi = 0;
}

Lane::~Lane()
{
}

int Lane::get_distance(){
	return m_distance;
}
int Lane::get_laneId() {
	return m_laneId;
}
int Lane::get_nbEnnemi() {
	return m_nbEnnemi;
}

void Lane::set_laneId(int laneId) {
	m_laneId = laneId;
}
void Lane::set_distance(int distance) {
	m_distance = distance;
}
void Lane::set_nbEnnemi(int nbEnnemi) {
	m_nbEnnemi = nbEnnemi;
}