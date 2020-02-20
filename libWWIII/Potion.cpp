#include "Potion.h"

using namespace std;

Potion::Potion() : Item() 
{
	m_hp_restore = 0;
}
Potion::~Potion() {
	
}

long Potion::get_hp_restore() {
	return m_hp_restore;
}
void Potion::set_hp_restore(long hpRestore) {
	m_hp_restore = hpRestore;
}

void Potion::afficher() {
	cout << left << setw(8) << m_id << "Potion : " << setw(30) << m_name << "Prit d'achat : " << setw(10) << m_price_buy;
	cout << "Prit de vente : " << setw(10) << m_price_sell << "Nombre d'Hp restore : " << m_hp_restore << "\n";
}