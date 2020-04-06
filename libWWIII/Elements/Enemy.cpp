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
void Enemy::set_next_enemy(Enemy *next_enemy) {
	m_next_enemy = next_enemy;
}

void Enemy::step() {
	Coord next_position = m_position + DirTools::vectors[m_dir];
	if (m_lane->is_empty(next_position)) {
		/* Mouvement moins avancé */
		if (m_jeu->niveau().should_move())
			m_position = next_position;

		/*
		 * TODO: Mouvement plus avancé
		 * Les collisions sont mal gérées
		 */
		/*
		if (m_jeu->niveau().should_move()) {
			m_position = next_position;
		} else if (m_next_enemy != nullptr) {
			m_next_enemy->step();
			return step();
		}
		*/
	}
}
