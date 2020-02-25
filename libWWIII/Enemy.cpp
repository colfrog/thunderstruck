#include "Enemy.h"

Enemy::Enemy() : Personnage() {
	drop = 1;
}
Enemy::Enemy(string n) : Personnage(n) {
	drop = 1;
}
Enemy::~Enemy() {

}

int Enemy::getDrop() {
	return drop;
}
void Enemy::setDrop(int dr) {
	drop = dr;
}

void Enemy::levelUp() {
	actualLevel() =	actualLevel() + 1;
}

void Enemy::step() {
	if (actualLevel().should_move()) {
		position() = (position() + 1);
	}
}