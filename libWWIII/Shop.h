#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctype.h>

#include "Items/Potion.h"
#include "Items/Weapon.h"
#include "Items/Defense.h"
#include "Elements/Personnage.h"

//Nom du fichier pour la liste de tous les items du jeu
#define N0M_FICHIER "listes_des_items.txt"

/*********** Catégorie d'item : *************
*	1.Potion =>	POTION (valeur:1 entier)
*	2.Weapon => WEAPON (valeur:2)
*	3.Defense => DEFENSE (Valeur:3 entier)
********************************************/

using namespace std;

class Shop {
public:
	Shop(Jeu *jeu = nullptr);
	~Shop();

	vector<Potion>  get_list_potion();
	vector<Weapon>  get_list_weapon();
	vector<Defense>  get_list_defense();
	Personnage get_seller();

	//Méthode pour vendre une potion du joueur au Shop
	void sell_potion(Potion potion);
	//Méthode pour vendre une arme du joueur au Shop
	void sell_weapon(Weapon weapon);
	//Méthode pour vendre une defense du joueur au Shop
	void sell_defense(Defense armure);

	//Méthode pour acheter une potion du Shop
	Potion buy_potion(int id);
	//Méthode pour acheter une arme du Shop
	Weapon buy_weapon(int id);
	//Méthode pour acheter une armure du Shop
	Defense buy_defense(int id);

	//La fonction retourne le montant payé si la tour est reparee et -1 si la tour n'est pas reparee
	int reparing_tour(int argent);
	//La fonction retourne le montant payé si la tour est upgradee et -1 si la tour n'est pas upgradee
	int upgrading_tour(int argent);

	//Méthode pour afficher tous les items du shop
	void show_list();

	//Méthode pour réorganiser la liste de la catégorie d'item en entré en ordre alphabétique
	void reorganize_shop(int id);

	//Méthode pour trouver la catégorie d'item qu'est l'id en entré
	int find_category(int id);
	//Méthode pour trouver l'id en entré de la potion si celle-ci est dans la liste
	int find_potion(int id);
	//Méthode pour trouver l'id en entré de l'arme si celle-ci est dans la liste
	int find_weapon(int id);
	//Méthode pour trouver l'id en entré de la defense si celle-ci est dans la liste
	int find_defense(int id);

private:
	vector<Potion> m_list_potion;
	vector<Weapon> m_list_weapon;
	vector<Defense> m_list_defense;
	Personnage m_seller;
	Jeu *m_jeu;
};
