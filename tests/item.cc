#include <iostream>
#include <Shop.h>

using namespace std;

int main() {
	//Test de la classe Item
	Item item;
	item.set_id(000);
	item.set_name("item");
	item.set_price_buy(-2);
	item.set_price_sell(1000);

	item.afficher();
	return 0;
}
