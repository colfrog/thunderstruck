#include "Lane.h"

Lane::Lane(Direction dir) : m_dir(dir)
{
	m_laneId = 0;
	m_distance = 100;
	m_total_nbEnemy = 0;
	m_actual_nbEnemy = 0;
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
	return m_total_nbEnemy;
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
	m_total_nbEnemy = nbEnnemi;
	m_list_enemy.clear();
}

bool Lane::all_dead() {
	return m_total_nbEnemy - m_actual_nbEnemy == 0;
}

Enemy Lane::changer_typeEnemy(string name, int drop) {
	Enemy enemy(name);
	enemy.setDrop(drop);
	return enemy;
}
Enemy Lane::changer_typeEnemy(string name, int drop, Weapon weapon, Defense defense) {
	Enemy enemy(name);
	enemy.setDrop(drop);
	enemy.setWeapon(weapon);
	enemy.setDefense(defense);
	return enemy;
}

void Lane::step() {
	Enemy enemy = changer_typeEnemy("Iranien", 10);
	int spawn = rand() % 10 + 1;
	for (int i = 0; i < m_actual_nbEnemy; i++) {
		// Fait avancer l'enemy s'il peut bouger et s'il n'est pas arriver à la distance de la tour
		if (m_list_enemy.at(i).actualLevel().should_move() == true && m_list_enemy.at(i).position().x() < get_distance()) {
			m_list_enemy.at(i).step();
		}
	}
	//Fait spawner un nouvelle enemy si la variable est plus grande que 5 et que le nombre d'enemis est plus petit que le total d'enemis pour cette lane
	if (m_actual_nbEnemy < m_total_nbEnemy && spawn > 5) {
		m_list_enemy.push_back(enemy);
		m_actual_nbEnemy++;
	}
}
