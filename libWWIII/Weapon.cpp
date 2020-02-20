#include "Weapon.h"

Weapon::Weapon() : Item()
{
	m_attack = 0;
	m_frequence = 0;
}

Weapon::~Weapon()
{
	
}

long Weapon::get_attack() {
	return m_attack;
}
long Weapon::get_frequence() {
	return m_frequence;
}

void Weapon::set_attack(long a) {
	m_attack = a;
}
void Weapon::set_frequence(long f) {
	m_frequence = f;
}

void Weapon::afficher() {
	cout << left << setw(8) << m_id << "Arme : " << setw(32) << m_name << "Prit d'achat : " << setw(10) << m_price_buy;
	cout << "Prit de vente : " << setw(10) << m_price_sell << "Degat d'attaque : " << setw(11) << m_attack;
	cout << "Frequence d'attaque : " << m_frequence << endl;
}