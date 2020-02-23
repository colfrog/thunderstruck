#include "Enemy.h"

Enemy::Enemy() : Personnage() {
	name = "";
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
