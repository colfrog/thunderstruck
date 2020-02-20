#include <iostream>
#include <Shop.h>

using namespace std;

int main() {
	//Test de la classe Item
	Item potion;
	potion.setId(POTION);
	potion.setName("potion de vie");
	potion.setPriceBuy(-2);
	potion.setPriceSell(1000);

	cout << potion.getId() << " " << potion.getName() << " " <<
		potion.getPriceBuy() << " " << potion.getPriceSell() << endl;
	return 0;
}
