#include "Enemy.h"

Enemy::Enemy() {
	name = "";
	drop = 1;
}
Enemy::Enemy(string n) {
	name = n;
	drop = 1;
}
Enemy::~Enemy() {

}

string Enemy::getName() {
	return name;
}
void Enemy::setName(string n) {
	name = n;
}

int Enemy::getDrop() {
	return drop;
}
void Enemy::setDrop(int dr) {
	drop = dr;
}
