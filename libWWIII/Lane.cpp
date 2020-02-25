#include "Lane.h"

Lane::Lane(const Jeu *jeu, Direction dir) :
	Element(jeu),
	m_dir(dir)
{}

Lane::~Lane() {}

int Lane::get_distance(){
	return m_distance;
}
int Lane::get_lane_id() {
	return m_lane_id;
}
int Lane::get_enemy_count() {
	return m_enemies.size();
}
Direction Lane::get_direction() {
	return m_dir;
}

void Lane::set_lane_id(int lane_id) {
	m_lane_id = lane_id;
}
void Lane::set_distance(int distance) {
	m_distance = distance;
}

Enemy Lane::make_enemy(string name, int drop) {
	Enemy enemy(m_jeu, name);
	enemy.set_drop(drop);
	return enemy;
}
Enemy Lane::make_enemy(string name, int drop, Weapon weapon, Defense defense) {
	Enemy enemy(m_jeu, name);
	enemy.set_drop(drop);
	enemy.set_weapon(weapon);
	enemy.set_defense(defense);
	return enemy;
}

void Lane::step() {
	for (Enemy e : m_enemies)
		e.step();
}
