#include "Defense.h"

Defense::Defense() : Item()
{
	m_evasion = 0;
	m_armure = 0;
}

Defense::~Defense()
{
}

float Defense::get_evasion() const {
	return m_evasion;
}
int  Defense::get_armure() const {
	return m_armure;
}

void Defense::set_evasion(int evasion) {
	m_evasion = evasion;
}
void Defense::set_armure(int armure) {
	m_armure = armure;
}

void Defense::afficher() {
	cout << left << setw(8) << m_id << "Defense : " << setw(29) << m_name << "Prit d'achat : " << setw(10) << m_price_buy;
	cout << "Prit de vente : " << setw(10) << m_price_sell << "Point d'armure : " << setw(12) << m_armure;
	cout << "Pourcentage d'evasion : " << m_evasion << endl;
}
