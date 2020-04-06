#include "Tour.h"

Tour::Tour(Jeu *jeu, std::string player_name) :
	Element(jeu),
	m_player(Player(jeu, player_name))
{
	Weapon w;
	w.set_attack(100);
	Defense d;
	d.set_armure(1);
	m_player.set_weapon(w);
	m_player.set_defense(d);
}
Tour::~Tour() {}

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

int Tour::attack(Element &elem, int mod) {
	return m_player.attack(elem, mod);
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

void Tour::show() const {
	std::cout << "Tour: " << m_hp << " hp" << std::endl;
	m_player.show();
}
