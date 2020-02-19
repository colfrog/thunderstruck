#include <iostream>
#include <Shop.h>

using namespace std;

int main() {
	//Tests de la classe Shop
	Shop magasin;
	Item item;

	cout << endl << endl;
	magasin.showList();
	cout << endl << endl;

	item = magasin.buyItem("sniper");
	cout << endl << endl;

	magasin.showList();
	cout << endl << endl;

	item = magasin.buyItem("lol");
	return 0;
}
