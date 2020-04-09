#include "Personnage.h"
#include "Jeu.h"

Personnage::Personnage(Jeu *jeu, string n) :
	Element(jeu),
	m_name(n)
{
	m_id = m_jeu->new_character_id();
	m_jeu->declare_spawned(this);
}
Personnage::~Personnage() {}

int Personnage::damage(const Weapon &w, int mod) {
	int damage = w.get_attack() + mod;
	int armor = m_defense.get_armure();
	unsigned int hp_initial = m_hp;

	if (armor >= damage)
		return 0;

	if (m_hp >= damage) {
		m_hp -= w.get_attack() - armor + mod;
	} else {
		m_jeu->declare_dead(this);
		m_hp = 0;
	}

	return hp_initial - m_hp;
}

int Personnage::attack(Element &elem, int mod) {
	return elem.damage(m_weapon, mod);
}

uint64_t Personnage::get_id() {
	return m_id;
}

string Personnage::get_name() {
	return m_name;
}
void Personnage::set_name(string n) {
	m_name = n;
}

unsigned long Personnage::get_hp() {
	return m_hp;
}
void Personnage::set_hp(unsigned long hp) {
	m_hp = hp;
}

Defense Personnage::get_defense() {
	return m_defense;
}
void Personnage::set_defense(Defense def) {
	m_defense = def;
}

Weapon Personnage::get_weapon() {
	return m_weapon;
}
void Personnage::set_weapon(Weapon w) {
	m_weapon = w;
}

bool Personnage::is_dead() {
	return m_hp == 0;
}

Direction Personnage::direction() {
	return m_dir;
}

void Personnage::set_direction(Direction dir) {
	m_dir = dir;
}

void Personnage::turn_left() {
	m_dir = DirTools::lefts[m_dir];
}

void Personnage::turn_right() {
	m_dir = DirTools::rights[m_dir];
}

void Personnage::show() const {
	std::cout << "Personnage: " << m_name << "(" << m_id << ")" <<
		" - " << m_hp << " hp, " <<
		m_weapon.get_attack() << " attack, " <<
		m_defense.get_armure() << " defense, " <<
		"direction(" << DirTools::dir_names[m_dir] << "), " <<
		m_position.to_string() << std::endl;
}
