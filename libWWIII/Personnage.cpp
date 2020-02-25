#include "Personnage.h"

Personnage::Personnage(const Jeu *jeu, string n) :
	Element(jeu),
	m_name(n)
{}
Personnage::~Personnage() {}

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
