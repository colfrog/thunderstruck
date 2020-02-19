#include "Shop.h"

//À modifier quand les classes enfants de Item vont être implémenter
Shop::Shop() {
	ifstream file;
	file.open("ListItem.txt", ios_base::in);
	Item actualItem;
	string name;
	int sell, buy;
	char id;

	if (file.is_open()) {
		while (!file.eof()) {
			file.get(id);
			
			if ('0' == id) { //Potion
				actualItem.setId(POTION);
				file >> buy >> sell >> name;
			}
			else if ('1' == id) { //Weapon
				actualItem.setId(WEAPON);
				file >> buy >> sell >> name;
			}
			else if ('2' == id) { //Armor
				actualItem.setId(ARMOR);
				file >> buy >> sell >> name;
			}
			else {
				id = '9';
				getline(file, name);
			}

			if (id != '9') {
				file.ignore();

				actualItem.setName(name);
				actualItem.setPriceBuy(buy);
				actualItem.setPriceSell(sell);

				listItem.push_back(actualItem);
			}
		}

		reorganizeShop();

		file.close();
	} else {
		cout << "Erreur impossible d'ouvrir le shop" << endl;
	}
	
}

//À Modifier quand la classe Personnage va être implémenter
Shop::~Shop() {
	listItem.clear();
	//delete seller
}

vector<Item>  Shop::getListItem() {
	return listItem;
}

void Shop::sellItem(Item item) {
	listItem.push_back(item);

	reorganizeShop();
}

Item Shop::buyItem(string name) {
	Item item;
	int itemBought = findItem(name);

	if (itemBought != -1) {
		item = listItem.at(itemBought);
		listItem.erase(listItem.begin() + itemBought);
		//cout << "L'item " << name << " a ete vendu. \n";
	}
	else {
		cout << "L'item " << name << " n'est pas dans le magasin." << endl;
	}

	return item;
}

void Shop::showList() {
	for (unsigned int i = 0; i < listItem.size(); i++) {
		if (POTION == listItem.at(i).getId()) {
			cout << "Potion : " << listItem.at(i).getName() << "	Prix d'achat : " << listItem.at(i).getPriceBuy();
			cout << " Prix de vente : " << listItem.at(i).getPriceSell() << endl;
		}
		else if (WEAPON == listItem.at(i).getId()) {
			cout << "Arme : " << listItem.at(i).getName() << "	Prix d'achat : " << listItem.at(i).getPriceBuy();
			cout << " Prix de vente : " << listItem.at(i).getPriceSell() << endl;
		}
		else if (ARMOR == listItem.at(i).getId()) {
			cout << "Armure : " << listItem.at(i).getName() << "	Prix d'achat : " << listItem.at(i).getPriceBuy();
			cout << " Prix de vente : " << listItem.at(i).getPriceSell() << endl;
		}
	}
}

//À modifier quand les classe enfant de Item vont être fait
void Shop::showStatsItem(int index) {
	
}

void Shop::reorganizeShop() {
	vector<string> nom;
	vector<Item> temp;
	Item item;
	int potion = 0, weapon = 0, armor = 0;

	//Réorganise les items selon leur catégorie
	for (int i = 0; i < listItem.size(); i++) {
		if (listItem.at(i).getId() == POTION) {
			item = listItem.at(i);
			listItem.erase(listItem.begin() + i);
			listItem.insert(listItem.begin(), item);
			potion++;
		} else if (listItem.at(i).getId() == WEAPON) {
			item = listItem.at(i);
			listItem.erase(listItem.begin() + i);
			listItem.insert(listItem.begin()+potion, item);
			weapon++;
		} else {
			item = listItem.at(i);
			listItem.erase(listItem.begin() + i);
			listItem.push_back(item);
			armor++;
		}
	}

	temp = listItem;

	//Tri les noms selon leur catégories
	for (int i = 0; i < listItem.size(); i++) {
		nom.push_back(listItem.at(i).getName());
	}
	sort(nom.begin(), nom.begin()+potion-1);
	sort(nom.begin()+potion, nom.begin()+potion+weapon-1);
	sort(nom.begin()+potion+weapon, nom.end());

	for (int i = 0; i < listItem.size(); i++) {
		for (int j = 0; j < listItem.size(); j++) {
			if (listItem.at(j).getName() == nom.at(i)) {
				temp.at(j) = listItem.at(i);
			}
		}
	}
	listItem = temp;
}

int Shop::findItem(string name) {
	for (unsigned int i = 0; i < listItem.size(); i++) {
		if (listItem.at(i).getName() == name) {
			return i;
		}
	}

	return -1;
}