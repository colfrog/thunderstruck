#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

/** Catégorie d'item :
*	1.Potion =>	POTION (valeur:1 entier)
*	2.Weapon => WEAPON (valeur:2)
*	3.Defense => DEFENSE (Valeur:3 entier)
********************************************/
#define POTION 1
#define WEAPON 2
#define DEFENSE 3

using namespace std;

class Item {
public:
	Item();
	~Item();

	void set_id(int id);
	void set_name(string name);
	void set_price_buy(int price_buy);
	void set_price_sell(int price_sell);

	int get_id();
	string get_name();
	int get_price_buy();
	int get_price_sell();

	virtual void afficher();
protected:
	//categorie de l'item suivi de son identifiant personnel
	int m_id;
	string m_name;
	int m_price_buy;
	int m_price_sell;
};