#include <iostream>
#include <Shop.h>

using namespace std;

int main() {
	//Test de la classe Item
	Item potion;
	potion.set_id(POTION);
	potion.set_name("potion de vie");
	potion.set_price_buy(-2);
	potion.set_price_sell(1000);

	cout << potion.get_id() << " " << potion.get_name() << " " <<
		potion.get_price_buy() << " " << potion.get_price_sell() << endl;
	return 0;
}
