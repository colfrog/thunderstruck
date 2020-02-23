
#include "Player.h"

Player::Player() : Personnage() {
	stats = Stats();
	argent = 0;
}
Player::Player(string n) : Personnage(n) {
	stats = Stats();
	argent = 0;
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
