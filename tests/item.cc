#include <iostream>
#include <assert.h>
#include <Shop.h>

using namespace std;

int main() {
	//Test de la classe Item
	Item item;

	assert(item.get_id() == -1 && item.get_name() == "" && item.get_price_sell() == 0 && item.get_price_buy() == 0);

	item.set_id(000);
	item.set_name("item");
	item.set_price_buy(-2);
	item.set_price_sell(1000);

	assert(item.get_id() == 000);
	assert(item.get_name() == "item");
	assert(item.get_price_buy() == -2);
	assert(item.get_price_sell() == 1000);

	item.afficher();

	return 0;
}
