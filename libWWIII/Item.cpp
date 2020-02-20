#include "Item.h"

Item::Item() {
	m_id = -1;
	m_name = "";
	m_price_sell = 0;
	m_price_buy = 0;
}

Item::~Item() {

}

void Item::set_id(int id) {
		m_id = id;
}
void Item::set_name(string name) {
	m_name = name;
}
void Item::set_price_buy(int price_buy) {
	m_price_buy = price_buy;
}
void Item::set_price_sell(int price_sell) {
	m_price_sell = price_sell;
}

int Item::get_id() {
	return m_id;
}
string Item::get_name() {
	return m_name;
}
int Item::get_price_buy() {
	return m_price_buy;
}
int Item::get_price_sell() {
	return m_price_sell;
}

void Item::afficher() {
	cout << left << setw(8) << m_id << "Nom : " << setw(29) << m_name << "Prit d'achat : " << setw(10) << m_price_buy;
	cout << "Prit de vente : " << setw(10) << m_price_sell << endl;
}