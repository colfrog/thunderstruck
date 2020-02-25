#include "Tour.h"

Tour::Tour(const Jeu *jeu, std::string player_name) :
	Element(jeu),
	m_player(Player(jeu, player_name))
{}
Tour::~Tour() {}

/* dommage retourne les dégâts pris */
int Tour::dommage(Weapon &w) {
	int damage = w.get_attack();
	if (m_hp > damage) {
		m_hp -= damage;	
	}
	else {
		damage -= m_hp;
		m_hp = 0;
		w.set_attack(damage);
		m_player.dommage(w);
	}
	return damage;
}

Player Tour::player() {
	return m_player;
}
unsigned int Tour::hp() {
	return m_hp;
}

void Tour::set_hp(unsigned int hp) {
	m_hp = hp;
}
void Tour::set_player(Player player) {
	m_player = player;
}

void Tour::step() {
	m_player.step();
}
