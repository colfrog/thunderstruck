
#include "Player.h"

Player::Player() {
	name = "";
	stats = Stats();
	argent = 0;
}
Player::Player(string n) {
	name = n;
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

string Player::getName() {
	return name;
}
void Player::setName(string n) {
	name = n;
}

int Player::getArgent() {
	return argent;
}
void Player::setArgent(int arg) {
	argent = arg;
}
