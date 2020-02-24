#include <cmath>

#include "Shop.h"


Shop::Shop() {
	m_seller = Personnage("Melania Trump");
	m_seller.getWeapon().set_attack(20);


	ifstream file;
	file.open(N0M_FICHIER, ios_base::in);
	Potion actual_potion;
	Weapon actual_weapon; 
	Defense actual_defense;
	string name;
	char  category_char,id_char[3];
	int id[2], sell, buy, attribut1, attribut2, upgrade1, upgrade2;

	if (file.is_open()) {
		while (!file.eof()) {
			file.get(category_char);
			//opération pour trouver quelle type d'item est l'id actuel lu dans le fichier

			if (' ' == category_char || '\n' == category_char) {

			}
			else if ('1' == category_char) { //Potion
				for (int i = 0; i <3 ; i++) {
					file.get(id_char[i]);
					if (i < 2) {
						id[i] = id_char[i] - 48;
					}
				}
				actual_potion.set_id(POTION * pow(10,2) + id[0]*pow(10,1) + id[1]) ;
				// attribut1 est l'attribut pour la vie donnee par la potion
				file >> buy >> sell >> name >> attribut1; 

				actual_potion.set_name(name);
				actual_potion.set_price_buy(buy);
				actual_potion.set_price_sell(sell);
				actual_potion.set_hp_restore(attribut1);

				m_list_potion.push_back(actual_potion);
				file.ignore();
			}
			else if ('2' == category_char) { //Weapon
				
				for (int i = 0; i < 3; i++) {
					file.get(id_char[i]);
					if (i < 2) {
						id[i] = id_char[i] - 48;
					}
				}
				actual_weapon.set_id(WEAPON * pow(10, 2) + id[0] * pow(10, 1) + id[1]);
				// attribut1 est l'attribut pour les degats d'attaque de l'arme
				// attribut2 est l'attribut pour la frequence d'attaque de l'arme
				//	upgrade1 est la variable pour l'upgrade de l'attack
				//	upgrade2 est la variable pour l'upgrade de la frequence
				file >> buy >> sell >> name >> attribut1 >> attribut2 >> upgrade1 >> upgrade2;

				actual_weapon.set_name(name);
				actual_weapon.set_price_buy(buy);
				actual_weapon.set_price_sell(sell);
				actual_weapon.set_attack(attribut1);
				actual_weapon.set_frequence(attribut2);
				actual_weapon.set_upgrade_attack(upgrade1);
				actual_weapon.set_upgrade_frequence(upgrade2);

				m_list_weapon.push_back(actual_weapon);
				file.ignore();
			}
			else if ('3' == category_char) { //Defense
				for (int i = 0; i < 3; i++) {
					file.get(id_char[i]);
					if (i < 2) {
						id[i] = id_char[i] - 48;
					}
				}
				actual_defense.set_id(DEFENSE * pow(10, 2) + id[0] * pow(10, 1) + id[1]);
				// attribut1 est l'attribut pour l'armure de la defense actuel
				// attribut2 est l'attribut pour l'evasion de la defense actuel
				file >> buy >> sell >> name >> attribut1 >> attribut2;

				actual_defense.set_name(name);
				actual_defense.set_price_buy(buy);
				actual_defense.set_price_sell(sell);
				actual_defense.set_armure(attribut1);
				actual_defense.set_evasion(attribut2);

				m_list_defense.push_back(actual_defense);
				file.ignore();
			}
			else {
				getline(file, name);
			}

			
		}
		reorganize_shop(POTION);
		reorganize_shop(WEAPON);
		reorganize_shop(DEFENSE);

		file.close();
	} else {
		cout << "Erreur impossible d'ouvrir le shop" << endl;
	}
}

Shop::~Shop() {
	m_list_potion.clear();
	m_list_weapon.clear();
	m_list_defense.clear();
}

vector<Potion> Shop::get_list_potion() {
	return m_list_potion;
}
vector<Weapon> Shop::get_list_weapon() {
	return m_list_weapon;
}
vector<Defense> Shop::get_list_defense() {
	return m_list_defense;
}

void Shop::sell_potion(Potion potion) {
	m_list_potion.push_back(potion);

	reorganize_shop(potion.get_id());
}
void Shop::sell_weapon(Weapon weapon) {
	m_list_weapon.push_back(weapon);

	reorganize_shop(weapon.get_id());
}
void Shop::sell_defense(Defense armure) {
	m_list_defense.push_back(armure);

	reorganize_shop(armure.get_id());
}

Potion Shop::buy_potion(int id) {
	Potion potion;
	int index = find_potion(id);

	if (index == -1) {
		cout << "La potion " << id << " n'est pas dans le magasin." << endl;
	}
	else {
		potion = m_list_potion.at(index);
		m_list_potion.erase(m_list_potion.begin() + index);
	}

	return potion;
}
Weapon Shop::buy_weapon(int id) {
	Weapon weapon;
	int index = find_weapon(id);

	if (index == -1) {
		cout << "L'arme " << id << " n'est pas dans le magasin." << endl;
	}
	else {
		weapon = m_list_weapon.at(index);
		m_list_weapon.erase(m_list_weapon.begin() + index);
	}

	return weapon;
}
Defense Shop::buy_defense(int id) {
	Defense defense;
	int index = find_defense(id);

	if (index == -1) {
		cout << "La potion " << id << " n'est pas dans le magasin." << endl;
	}
	else {
		defense = m_list_defense.at(index);
		m_list_defense.erase(m_list_defense.begin() + index);
	}

	return defense;
}

void Shop::show_list() {
	cout << "\n====================================================================================================================================================================\n";
	cout << "Liste de potion\n";
	for (unsigned int i = 0; i < m_list_potion.size(); i++) {
		m_list_potion.at(i).afficher();
	}
	cout << endl;
	cout << "====================================================================================================================================================================\n";
	cout << "Liste d'arme\n";
	for (unsigned int i = 0; i < m_list_weapon.size(); i++) {
		m_list_weapon.at(i).afficher();
	}
	cout << endl;
	cout << "====================================================================================================================================================================\n";
	cout << "Liste de defense\n";
	for (unsigned int i = 0; i < m_list_defense.size(); i++) {
		m_list_defense.at(i).afficher();
	}
	cout << endl;
	cout << "====================================================================================================================================================================\n\n";
}

/*void Shop::showStatsItem(int id) {
	int category = find_category(id), index;

	if (category == POTION) {
		index = find_potion(id);
		if (index == -1) {
			cout << "La potion n'est pas dans l'index du magasin\n";
		}
		else {
			m_list_potion.at(index).afficher();
		}
	} else if (category == WEAPON) {
		index = find_weapon(id);
		if (index == -1) {
			cout << "L'arme n'est pas dans l'index du magasin\n";
		}
		else {
			m_list_weapon.at(index).afficher();
		}
	} else if (category == DEFENSE) {
		index = find_defense(id);
		if (index == -1) {
			cout << "La defense n'est pas dans l'index du magasin\n";
		}
		else {
			m_list_defense.at(index).afficher();
		}
	}
	
}*/

void Shop::reorganize_shop(int id) {
	//Vector d'entier qui va réorganiser les items de la catégorie de l'id en ordre du moinx cher au plus cher pour le prix d'achat
	vector<int> price_buy;
	int category = find_category(id);

	
	if (category == 1) {
		vector<Potion> temp_list;
		Potion pot;
		
		temp_list = m_list_potion;

		for (int i = 0; i < temp_list.size(); i++) {
			price_buy.push_back(temp_list.at(i).get_price_buy());
		}

		sort(price_buy.begin(), price_buy.end());

		for (int i = 0; i < temp_list.size(); i++) {
			for (int j = 0; j < m_list_potion.size(); j++) {
				if (m_list_potion.at(j).get_price_buy() == price_buy.at(i)) {
					temp_list.at(i) = m_list_potion.at(j);
				}
			}
		}

		m_list_potion = temp_list;
	}
	else if (category == 2) {
		vector<Weapon> temp_list;
		Weapon arm;

		temp_list = m_list_weapon;

		for (int i = 0; i < temp_list.size(); i++) {
			price_buy.push_back(temp_list.at(i).get_price_buy());
		}

		sort(price_buy.begin(), price_buy.end());

		for (int i = 0; i < temp_list.size(); i++) {
			for (int j = 0; j < m_list_weapon.size(); j++) {
				if (m_list_weapon.at(j).get_price_buy() == price_buy.at(i)) {
					temp_list.at(i) = m_list_weapon.at(j);
				}
			}
		}

		m_list_weapon = temp_list;
	}
	else if (category == 3) {
		vector<Defense> temp_list;
		Defense def;

		temp_list = m_list_defense;

		for (int i = 0; i < temp_list.size(); i++) {
			price_buy.push_back(temp_list.at(i).get_price_buy());
		}

		sort(price_buy.begin(), price_buy.end());

		for (int i = 0; i < temp_list.size(); i++) {
			for (int j = 0; j < m_list_defense.size(); j++) {
				if (m_list_defense.at(j).get_price_buy() == price_buy.at(i)) {
					temp_list.at(i) = m_list_defense.at(j);
				}
			}
		}

		m_list_defense = temp_list;
	} else {
		cout << "La liste d'item de cette catégorie n'existe pas.";
	}/**/
}

Player Shop::enter_shop(Player player) {
	cout << "Bienvenue dans mon magasion!\n";
	cout << "Mon nom est " << m_seller.getName() << endl;
	cout << endl;

	char option = 'A';
	char item_sell = 'D';
	int nb_insult = 0;

	do  {
		cout << "Choisir une option : \n";
		cout << "A) Acheter une arme\n";
		cout << "B) Vendre une arme\n";
		cout << "C) Insulter le vendeur\n";
		cout << "Q) Quitter le magasin\n";
		cin >> option;
		option = toupper(option);


		switch (option)
		{
		case 'A':
			int id, index, prix;
			show_list();

			cout << "Entrer l'id de l'item que vous voulez acheter\n";

			cin >> id;

			if (find_category(id) == POTION) {
				index = find_potion(id);
				prix = get_list_potion().at(index).get_price_buy();

				if (player.getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Potion potion = buy_potion(id);
					player.setArgent(player.getArgent() - prix);
					if (player.getHp() + potion.get_hp_restore() > 100) {
						player.setHP(100);
					}
					else {
						player.setHP(player.getHp() + potion.get_hp_restore());
					}
					cout << "Vous venez d'acheter la potion " << potion.get_name() << endl;
				}
			}
			else if (find_category(id) == WEAPON) {
				index = find_weapon(id);
				prix = get_list_weapon().at(index).get_price_buy();

				if (player.getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Weapon arme = buy_weapon(id);
					player.setArgent(player.getArgent() - prix);
					player.setWeapon(arme);
					cout << "Vous venez d'acheter l'arme " << player.getWeapon().get_name() << endl;
				}
			}
			else if (find_category(id) == DEFENSE) {
				index = find_defense(id);
				prix = get_list_defense().at(index).get_price_buy();

				if (player.getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Defense defense = buy_defense(id);
					player.setArgent(player.getArgent() - prix);
					player.setDefense(defense);
					cout << "Vous venez d'acheter la defense " << player.getDefense().get_name() << endl;
				}
			}
			else {
				cout << "L'id saisi n'existe pas\n";
			}

			cout << endl;

			break;
		case 'B':
			do {
				cout << "Quel item voulez-vous vendre?\n";
				cout << "A) Votre arme\nB) Votre defense\nC) Aucun item\n";

				cin >> item_sell;
				item_sell = toupper(item_sell);
				int prix; 
				Weapon arme;
				Defense def;

				switch (item_sell)
				{
				case 'A':
					
					prix = player.getWeapon().get_price_sell();
					player.setArgent(player.getArgent() + prix);
					sell_weapon(player.getWeapon());
					player.setWeapon(arme);
					cout << "Vous venez de vendre votre arme\n";
					break;
				case 'B':
					prix = player.getDefense().get_price_sell();
					player.setArgent(player.getArgent() + prix);
					sell_defense(player.getDefense());
					player.setDefense(def);
					cout << "Vous venez de vendre votre defense\n";
					break;
				case 'C':
					break;
				default:
					cout << "Cette option n'existe! Veuillez entrer une option existante.\n";
					break;
				}
			} while (item_sell != 'C');
			cout << endl;
			break;
		case 'C':
			nb_insult++;
			if (nb_insult < 3) {
				cout << "Vous venez d'insulter " << m_seller.getName() << endl;
				cout << m_seller.getName() << " commence a se facher\n";
			}
			else {
				cout << "Vous venez d'insulter " << m_seller.getName() << endl;
				cout << m_seller.getName() << " est fache et elle vous giffle\n";
				player.setHP(player.getHp() - m_seller.getWeapon().get_attack());
				cout << "Vous vous prenez " << m_seller.getWeapon().get_attack() << " points de degats\n";
			}
			cout << endl;
			break;
		case 'Q':
			break;
		default:
			cout << "Cette option n'existe pas\n";
				break;
		}		
	} while (option != 'Q');

	return player;
}

int Shop::find_potion(int id) {
	int index = -1;
	for (unsigned int i = 0; i < m_list_potion.size(); i++) {
		if (m_list_potion.at(i).get_id() == id) {
			index = i;
			i = m_list_potion.size();
		}
	}

	return index;
}
int Shop::find_weapon(int id) {
	int index = -1;
	for (unsigned int i = 0; i < m_list_weapon.size(); i++) {
		if (m_list_weapon.at(i).get_id() == id) {
			index = i;
			i = m_list_weapon.size();
		}
	}

	return index;
}
int Shop::find_defense(int id) {
	int index = -1;
	for (unsigned int i = 0; i < m_list_defense.size(); i++) {
		if (m_list_defense.at(i).get_id() == id) {
			index = i;
			i = m_list_defense.size();
		}
	}

	return index;
}

int Shop::find_category(int id) {
	double category = id;


	while (category >= 10) {
		category /= 10;
	}

	return (int)category;
}
