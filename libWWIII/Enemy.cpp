#include "Enemy.h"

Enemy::Enemy(const Jeu *jeu, const Lane *lane, string n) :
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
}

void Enemy::levelUp() {
	actualLevel() =	actualLevel() + 1;
}

void Enemy::step() {
	if (actualLevel().should_move()) {
		position() = (position() + 1);
	}
}