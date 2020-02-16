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

	//M�thode pour vendre un item du joueur au Shop
	void sellItem(Item item);

	//M�thode pour acheter un item du Shop � partir du nom de l'item
	Item buyItem(string name);

	//M�thode pour afficher tous les items du shop
	void showList();

	//M�thode pour afficher les stats d'un item
	//index est la position de l'item dans listItem
	void showStatsItem(int index);

	//M�thode pour r�organiser la liste d'item selon la cat�gorie de ceux-ci et ensuite en ordre alphab�tique
	void reorganizeShop();

private:
	int findItem(string name);
	vector<Item> listItem;
	//seller (Personnage)
};

#endif // !1

