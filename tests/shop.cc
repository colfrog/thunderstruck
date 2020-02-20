#include <iostream>
#include <Shop.h>

using namespace std;

int main() {
	//Tests de la classe Shop
	Shop magasin;
	Potion potion;
	Weapon arme;
	Defense defense;/**/
	int potion_i = POTION * pow(10, 2) + 01;
	int arme_id = WEAPON * pow(10, 2) + 04;
	int defense_id = DEFENSE * pow(10, 2) + 06;/**/

	cout << "Test des items vide" << endl;
	potion.afficher();
	arme.afficher();
	defense.afficher();
	cout << endl << endl;

	cout << "Test du magasin cr??" << endl;

	magasin.showList();
	cout << endl << endl;

	cout << "Test d'acheter une arme du magasin" << endl;
	arme = magasin.buy_weapon(arme_id);
	cout << endl << endl;

	magasin.showList();
	cout << endl << endl;

	cout << "Test d'acheter une potion qui n'est pas dans le magasin" << endl;
	potion = magasin.buy_potion(defense_id);
	cout << endl << endl;

	magasin.showList();
	cout << endl << endl;

	cout << "Test d'acheter une potion du magasin" << endl;
	potion = magasin.buy_potion(potion_i);

	cout << "Test d'acheter une potion du magasin" << endl;
	defense = magasin.buy_defense(defense_id);

	magasin.showList();
	cout << endl << endl;

	cout << "Test des items achet?s" << endl;
	arme.afficher();
	potion.afficher();
	defense.afficher();

	return 0;
}
