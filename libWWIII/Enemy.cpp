#include "Enemy.h"

Enemy::Enemy() : Personnage() {}
Enemy::Enemy(string n) : Personnage(n) {}
Enemy::~Enemy() {}

int Enemy::get_drop() {
	return m_drop;
}
void Enemy::set_drop(int dr) {
	m_drop = dr;
}

void Enemy::step() {
}
