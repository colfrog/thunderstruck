#pragma once

#ifndef SHOP.H


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Item.h"

using namespace std;

class Shop {
public:
	Shop();
	~Shop();

	vector<Item>  getListItem();

	//Méthode pour vendre un item du joueur au Shop
	void sellItem(Item item);

	//Méthode pour acheter un item du Shop à partir du nom de l'item
	Item buyItem(string name);

	//Méthode pour afficher tous les items du shop
	void showList();

	//Méthode pour afficher les stats d'un item
	//index est la position de l'item dans listItem
	void showStatsItem(int index);

	//Méthode pour réorganiser la liste d'item selon la catégorie de ceux-ci et ensuite en ordre alphabétique
	void reorganizeShop();

private:
	int findItem(string name);
	vector<Item> listItem;
	//seller (Personnage)
};

#endif // !1

