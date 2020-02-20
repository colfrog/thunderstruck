#pragma once

#ifndef SHOP.H


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Potion.h"
#include "Weapon.h"
#include "Defense.h"

//Nom du fichier pour la liste de tous les items du jeu
#define N0M_FICHIER "listes_des_items.txt"

/*********** Cat�gorie d'item : *************
*	1.Potion =>	POTION (valeur:1 entier)
*	2.Weapon => WEAPON (valeur:2)
*	3.Defense => DEFENSE (Valeur:3 entier)
********************************************/

using namespace std;

class Shop {
public:
	Shop();
	~Shop();

	vector<Potion>  get_list_potion();
	vector<Weapon>  get_list_weapon();
	vector<Defense>  get_list_defense();

	//M�thode pour vendre une potion du joueur au Shop
	void sell_potion(Potion potion);
	//M�thode pour vendre une arme du joueur au Shop
	void sell_weapon(Weapon weapon);
	//M�thode pour vendre une defense du joueur au Shop
	void sell_defense(Defense armure);

	//M�thode pour acheter une potion du Shop
	Potion buy_potion(int id);
	//M�thode pour acheter une arme du Shop
	Weapon buy_weapon(int id);
	//M�thode pour acheter une armure du Shop
	Defense buy_defense(int id);

	//M�thode pour afficher tous les items du shop
	void show_list();

	//M�thode pour afficher les stats d'un item
	//id est l'id de l'item
	//void showStatsItem(int id);

	//M�thode pour r�organiser la liste de la cat�gorie d'item en entr� en ordre alphab�tique
	void reorganize_shop(int id);

	//M�thode pour trouver la cat�gorie d'item qu'est l'id en entr�
	int find_category(int id);

private:
	//M�thode pour trouver l'id en entr� de la potion si celle-ci est dans la liste
	int find_potion(int id);
	//M�thode pour trouver l'id en entr� de l'arme si celle-ci est dans la liste
	int find_weapon(int id);
	//M�thode pour trouver l'id en entr� de la defense si celle-ci est dans la liste
	int find_defense(int id);
	
	vector<Potion> m_list_potion;
	vector<Weapon> m_list_weapon;
	vector<Defense> m_list_defense;
	//seller (Personnage)
};

#endif // !1/**/

