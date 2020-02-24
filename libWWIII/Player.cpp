
#include "Player.h"

Player::Player() : Personnage() {
	stats = Stats();
	argent = 0;
	hp_regen = 0;
}
Player::Player(string n) : Personnage(n) {
	stats = Stats();
	argent = 0;
	hp_regen = 0;
}
Player::~Player() {

}

Stats Player::getStats() {
	return stats;
}
void Player::setStats(Stats st) {
	stats = st;
}

int Player::getArgent() {
	return argent;
}
void Player::setArgent(int arg) {
	argent = arg;
}

void Player::step() {
	hp_regen++;
	if (hp_regen == 10 && getHp() > 0 && getHp() < 100) {
		setHP(getHp() + 1);
		hp_regen = 0;
	}
}
