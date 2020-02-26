#include "Tour.h"

Tour::Tour(Jeu *jeu, std::string player_name) :
	Element(jeu),
	m_player(Player(jeu, player_name))
{}
Tour::~Tour() {}

/* damage retourne les dégâts pris */
int Tour::damage(const Weapon &w, int mod) {
	int damage = w.get_attack() + mod;
	if (m_hp > damage) {
		/* On attaque la tour */
		m_hp -= damage;	
		return damage;
	} else {
		/* On attaque le joueur */
		damage -= m_hp;
		m_hp = 0;
		return m_player.damage(w, damage - w.get_attack());
	}
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
