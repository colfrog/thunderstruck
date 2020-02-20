#include <iostream>
#include "Shop.h"
#include "Potion.h"
#include "Weapon.h"
#include "Defense.h"
#include <Windows.h>

using namespace std;

void main(void) {
	bool test = true;
	//Test de la classe Item et ses enfants
	/*Item item;
	item.set_id(000);
	item.set_name("item");
	item.set_price_buy(-2);
	item.set_price_sell(1000);

	item.afficher();


	Potion potion;
	potion.set_id(POTION*pow(10, 3) + 102);
	potion.set_name("vie");
	potion.set_price_buy(-2);
	potion.set_price_sell(1000);
	potion.set_hp_restore(5);

	potion.afficher();


	Weapon arme;
	arme.set_id(WEAPON * pow(10,3) + 342);
	arme.set_name("fusil");
	arme.set_price_buy(-2);
	arme.set_price_sell(1000);
	arme.set_attack(999999999);
	arme.set_frequence(0);

	arme.afficher();


	Defense armor;
	armor.set_id(DEFENSE * pow(10, 3) + 999);
	armor.set_name("chandail");
	armor.set_price_buy(-2);
	armor.set_price_sell(1000);
	armor.set_armure(-20);
	armor.set_evasion(999999999);


	armor.afficher(); /**/


	//Test de la classe Shop
	Shop magasin;
	Potion potion;
	Weapon arme;
	Defense defense;/**/
	int potion_i = POTION * pow(10, 2) + 01;
	int arme_id = WEAPON * pow(10, 2) + 04;
	int defense_id = DEFENSE * pow(10, 2) + 06;/**/

	cout << "Test des items vide" << endl;
	arme.afficher();
	potion.afficher();
	defense.afficher();
	cout << endl << endl;

	cout << "Test du magasin créé" << endl;

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

	cout << "Test des items achetés" << endl;
	arme.afficher();
	potion.afficher();
	defense.afficher();/**/

	system("pause");
}