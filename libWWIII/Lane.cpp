#include "Lane.h"

Lane::Lane(Direction dir) : m_dir(dir)
{
	m_laneId = 0;
	m_distance = 100;
	m_nbEnnemi = 0;
}

Lane::~Lane()
{
	m_list_enemy.clear();
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
Direction Lane::get_direction() {
	return m_dir;
}

void Lane::set_laneId(int laneId) {
	m_laneId = laneId;
}
void Lane::set_distance(int distance) {
	m_distance = distance;
}
void Lane::set_nbEnnemi(int nbEnnemi) {
	m_nbEnnemi = nbEnnemi;
	m_list_enemy.clear();

	Enemy enemy = changer_typeEnemy("Iranien", 10);

	for (int i; i < nbEnnemi; i++) {
		m_list_enemy.push_back(enemy);
	}
}

Enemy Lane::changer_typeEnemy(string name, int drop) {
	Enemy enemy(name);
	enemy.setDrop(drop);
}
Enemy Lane::changer_typeEnemy(string name, int drop, Weapon weapon, Defense defense) {
	Enemy enemy(name);
	enemy.setDrop(drop);
	enemy.setWeapon(weapon);
	enemy.setDefense(defense);
}

void Lane::step() {
	for (int i = 0; i < m_nbEnnemi; i++) {
		m_list_enemy.at(i).step();
	}
}
