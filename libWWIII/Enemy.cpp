#include "Enemy.h"
#include "Jeu.h"

Enemy::Enemy(Jeu *jeu, Lane *lane, string n) :
	Personnage(jeu, n),
	m_lane(lane)
{}
Enemy::~Enemy() {}

int Enemy::get_drop() {
	return m_drop;
}
void Enemy::set_drop(int dr) {
	m_drop = dr;
}

void Enemy::step() {
	Coord next_position = m_position + DirTools::vectors[m_dir];
	if (m_lane->is_empty(next_position) && m_jeu->niveau().should_move())
		m_position = next_position;

	if (m_lane->reached_end(this)) {
		m_jeu->tour().damage(m_weapon);
		m_lane->remove_top_enemy();
	}
}
