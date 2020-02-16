#pragma once

#include <iostream>
#include <string>

#define POTION 0
#define WEAPON 1
#define ARMOR 2

using namespace std;

class Item {
public:
	Item();
	~Item();

	void setId(int item);
	void setName(string n);
	void setPriceBuy(int price);
	void setPriceSell(int price);

	int getId();
	string getName();
	unsigned int getPriceBuy();
	unsigned int getPriceSell();

private:
	//categorie de l'item
	int id;
	string name;
	unsigned int priceBuy;
	unsigned int priceSell;
};