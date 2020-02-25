#include "Tour.h"

Tour::Tour(const Jeu *jeu, std::string player_name) :
	Element(jeu),
	m_player(Player(jeu, player_name))
{}
Tour::~Tour() {}

Player Tour::get_player() {
	return m_player;
}

void Tour::set_player(Player player) {
	m_player = player;
}

void Tour::step() {
	m_player.step();
}
