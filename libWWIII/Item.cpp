#include "Item.h"

Item::Item() {
	id = -1;
	name = "";
	priceSell = 0;
	priceBuy = 0;
}

Item::~Item() {

}

void Item::setId(int item) {
	if (item < 0 || item > 2) {
		cout << "Cette catégorie d'item n'existe pas\n";
	}
	else {
		id = item;
	}
}
void Item::setName(string n) {
	name = n;
}
void Item::setPriceBuy(int price) {
	priceBuy = abs(price);
}
void Item::setPriceSell(int price) {
	priceSell = abs(price);
}

int Item::getId() {
	return id;
}
string Item::getName() {
	return name;
}
unsigned int Item::getPriceBuy() {
	return priceBuy;
}
unsigned int Item::getPriceSell() {
	return priceSell;
}
