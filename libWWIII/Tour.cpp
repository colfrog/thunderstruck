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

int Tour::upgrade_tour() {
	if (m_player.get_argent() >= m_total_hp * 1.5) {
		cout << "L'amélioration de la tour coute " << m_total_hp * 1.5 << ". Veux-tu améliorer la tour (Oui=O, Non=N)?\n";
		char choix;
		cin >> choix;
		choix = toupper(choix);

		if (choix == 'O') {
			m_player.set_argent(m_player.get_argent() - m_total_hp * 1.5);
			m_total_hp *= 2;
			m_hp = m_total_hp;
			return 0;
		}
	}

	return -1;
}
int Tour::reparer_tour() {
	if (m_player.get_argent() >= m_total_hp * 1.5) {
		cout << "La reparation de la tour coute " << m_total_hp - m_hp << ". Veux-tu reparer la tour (Oui=O, Non=N)?\n";
		char choix;
		cin >> choix;
		choix = toupper(choix);

		if (choix == 'O') {
			m_player.set_argent(m_player.get_argent() - m_total_hp  + m_hp);
			m_hp = m_total_hp;
			return 0;
		}
	}

	return -1;
}

void Tour::step() {
	m_player.step();
}

void Tour::show() const {
	std::cout << "Tour: " << m_hp << " hp" << std::endl;
	m_player.show();
}
