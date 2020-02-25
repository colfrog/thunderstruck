#include <cmath>
#include <iostream>
#include <assert.h>
#include <Shop.h>
#include "Player.h"

using namespace std;

int main() {
	//Tests de la classe Shop
	int test = 0;
	Shop magasin;
	Potion potion, potion_vide;
	Weapon arme, arme_vide;
	Defense defense, defense_vide;/**/
	int potion_id = POTION * pow(10, 2) + 01, nb_list_potion;
	int arme_id = WEAPON * pow(10, 2) + 04, nb_list_arme;
	int defense_id = DEFENSE * pow(10, 2) + 06, nb_list_defense;/**/

	//Test les items initialisé
		cout << "Test des items vide" << endl;

		potion.afficher();
		arme.afficher();
		defense.afficher();
		cout << endl << endl;
	assert(potion.get_id() == -1 && potion.get_name() == "" && potion.get_price_sell() == 0 &&
		potion.get_price_buy() == 0 && potion.get_hp_restore() == 0);
	assert(arme.get_id() == -1 && arme.get_name() == "" && arme.get_price_sell() == 0 &&
		arme.get_price_buy() == 0 && arme.get_attack() == 0 && arme.get_frequence() == 1 
		&& arme.get_upgrade_attack() == 0 && arme.get_upgrade_frequence() == 0);
	assert(defense.get_id() == -1 && defense.get_name() == "" && defense.get_price_sell() == 0 &&
		defense.get_price_buy() == 0 && defense.get_armure() == 0 && defense.get_evasion() == 0);

	
	//Test le magasin initialisé
	cout << "Test du magasin cree" << endl;

	magasin.show_list();
	cout << endl << endl;
	for (int i = 1; i < magasin.get_list_potion().size(); i++) {
		assert(magasin.find_category(magasin.get_list_potion().at(i).get_id()) == POTION);
		assert(magasin.get_list_potion().at(i).get_price_buy() > magasin.get_list_potion().at(i - 1).get_price_buy());
	}
	for (int i = 1; i < magasin.get_list_weapon().size(); i++) {
		assert(magasin.find_category(magasin.get_list_weapon().at(i).get_id()) == WEAPON);
		assert(magasin.get_list_weapon().at(i).get_price_buy() > magasin.get_list_weapon().at(i - 1).get_price_buy());
	}
	for (int i = 1; i < magasin.get_list_defense().size(); i++) {
		assert(magasin.find_category(magasin.get_list_defense().at(i).get_id()) == DEFENSE);
		assert(magasin.get_list_defense().at(i).get_price_buy() > magasin.get_list_defense().at(i - 1).get_price_buy());
	}

	//Test de la fonction acheter selon différents items
	cout << "Test d'acheter une arme du magasin" << endl;
	arme = magasin.buy_weapon(arme_id);
	cout << endl << endl;

	magasin.show_list();
	cout << endl << endl;

	cout << "Test d'acheter une potion qui n'est pas dans le magasin" << endl;
	potion = magasin.buy_potion(defense_id);
	cout << endl << endl;

	magasin.show_list();
	cout << endl << endl;

	cout << "Test d'acheter une potion du magasin" << endl;
	potion = magasin.buy_potion(potion_id);

	cout << "Test d'acheter une potion du magasin" << endl;
	defense = magasin.buy_defense(defense_id);
	
	magasin.show_list();
	cout << endl << endl;

	cout << "Test des items achetes" << endl;
	arme.afficher();
	potion.afficher();
	defense.afficher();	

	// Test d'achat d'arme
	assert(arme.get_id() == arme_id && magasin.buy_weapon(arme_id).get_id() == arme_vide.get_id()) ;
	// Test d'achat de potion
	assert(potion.get_id() == potion_id && magasin.buy_potion(potion_id).get_id() == potion_vide.get_id());
	// Test d'achat de defense
	assert(defense.get_id() == defense_id && magasin.buy_defense(defense_id).get_id() == defense_vide.get_id());

	// Test d'achat invalide
	potion = magasin.buy_potion(defense_id);
	assert(potion.get_id() == -1);

	defense = magasin.buy_defense(defense_id);

	return 0;
}
