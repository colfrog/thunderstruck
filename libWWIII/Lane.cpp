#include "Lane.h"
#include "Jeu.h"

Lane::Lane(Jeu *jeu, Direction dir) :
	Element(jeu),
	m_dir(dir)
{}

Lane::~Lane() {}

int Lane::damage(const Weapon &w, int mod) {
	if (m_enemies.empty())
		return 0;

	return m_enemies.front().damage(w, mod);
}

bool Lane::is_empty(const Coord &position) {
	for (const Enemy &e : m_enemies)
		if (position == e.position())
			return false;

	return true;
}

bool Lane::reached_end(const Enemy *e) {
	return e->position() == get_end_position();
}

void Lane::remove_top_enemy() {
	m_enemies.pop_front();
}

bool Lane::can_spawn() {
	return is_empty(m_position);
}

void Lane::spawn() {
	Enemy e = make_enemy("Zombie", 10);
	m_enemies.push_back(e);
}

void Lane::set_lane_id(int lane_id) {
	m_lane_id = lane_id;
}
void Lane::set_distance(int distance) {
	m_distance = distance;
}

Direction Lane::get_direction() {
	return m_dir;
}
Coord Lane::get_end_position() {
	// TODO: Rajouter à la distance si la tour est tombée
	return m_position + DirTools::vectors[m_dir]*m_distance;
}
int Lane::get_distance(){
	return m_distance;
}
int Lane::get_lane_id() {
	return m_lane_id;
}
int Lane::get_enemy_count() {
	return m_enemies.size();
}

Enemy Lane::make_enemy(string name, int drop) {
	Enemy enemy(m_jeu, this, name);
	enemy.set_position(m_position);
	enemy.set_direction(DirTools::opposites[m_dir]);
	enemy.set_drop(drop);
	return enemy;
}
Enemy Lane::make_enemy(string name, int drop, Weapon weapon, Defense defense) {
	Enemy enemy = make_enemy(name, drop);
	enemy.set_weapon(weapon);
	enemy.set_defense(defense);
	return enemy;
}

void Lane::step() {
	if (m_jeu->niveau().should_spawn() && can_spawn())
		spawn();

	for (Enemy &e : m_enemies)
		e.step();
}
