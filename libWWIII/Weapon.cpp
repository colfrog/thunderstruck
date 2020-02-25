#include "Weapon.h"

Weapon::Weapon() : Item()
{
	m_attack = 0;
	m_frequence = 1;
	m_upgrade_attack = 0;
	m_upgrade_frequence = 0;
}

Weapon::~Weapon()
{
	
}

long Weapon::get_attack() const {
	return m_attack;
}
long Weapon::get_frequence() const {
	return m_frequence;
}
long Weapon::get_upgrade_attack() const {
	return m_upgrade_attack;
}
long Weapon::get_upgrade_frequence() const {
	return m_upgrade_frequence;
}

void Weapon::set_attack(long a) {
	m_attack = a;
}
void Weapon::set_frequence(long f) {
	m_frequence = f;
}
void Weapon::set_upgrade_attack(long upgrade) {
	m_upgrade_attack = upgrade;
}
void Weapon::set_upgrade_frequence(long upgrade) {
	m_upgrade_frequence = upgrade;
}

void Weapon::upgrade_weapon() {
	m_attack += m_upgrade_attack;
	m_frequence += m_upgrade_frequence;
}

void Weapon::afficher() {
	cout << left << setw(8) << m_id << "Arme : " << setw(32) << m_name << "Prit d'achat : " << setw(10) << m_price_buy;
	cout << "Prit de vente : " << setw(10) << m_price_sell << "Degat d'attaque : " << setw(11) << m_attack;
	cout << "Frequence d'attaque : " << m_frequence << endl;
}