#include "Enemy.h"

Enemy::Enemy(const Jeu *jeu, string n) : Personnage(jeu, n) {}
Enemy::~Enemy() {}

int Enemy::get_drop() {
	return m_drop;
}
void Enemy::set_drop(int dr) {
	m_drop = dr;
}

void Enemy::step() {
}
