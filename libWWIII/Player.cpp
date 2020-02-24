
#include "Player.h"

Player::Player() : Personnage() {
	stats = Stats();
	argent = 0;
	hp_regen = 0;
}
Player::Player(string n) : Personnage(n) {
	stats = Stats();
	argent = 0;
	hp_regen = 0;
}
Player::~Player() {

}

Stats Player::getStats() {
	return stats;
}
void Player::setStats(Stats st) {
	stats = st;
}

int Player::getArgent() {
	return argent;
}
void Player::setArgent(int arg) {
	argent = arg;
}

Shop Player::getShop() {
	return shop;
}
void Player::setShop(Shop s) {
	shop = s;
}

void Player::enter_shop() {
	cout << "Bienvenue dans mon magasion!\n";
	cout << "Mon nom est " << shop.get_seller().getName() << endl;
	cout << endl;

	char option = 'A';
	char item_sell = 'D';
	int nb_insult = 0, prix;

	do {
		cout << "Choisir une option : \n";
		cout << "A) Acheter un item\n";
		cout << "B) Vendre un item\n";
		cout << "C) Ameliorer l'arme\n";
		cout << "D) Insulter le vendeur\n";
		cout << "Q) Quitter le magasin\n";
		cin >> option;
		option = toupper(option);


		switch (option)
		{
		case 'A':
			int id, index;
			shop.show_list();

			cout << "Entrer l'id de l'item que vous voulez acheter\n";

			cin >> id;

			if (shop.find_category(id) == POTION) {
				index = shop.find_potion(id);
				prix = shop.get_list_potion().at(index).get_price_buy();

				if (getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Potion potion = shop.buy_potion(id);
					setArgent(getArgent() - prix);
					if (getHp() + potion.get_hp_restore() > 100) {
						setHP(100);
					}
					else {
						setHP(getHp() + potion.get_hp_restore());
					}
					cout << "Vous venez d'acheter la potion " << potion.get_name() << endl;
				}
			}
			else if (shop.find_category(id) == WEAPON) {
				index = shop.find_weapon(id);
				prix = shop.get_list_weapon().at(index).get_price_buy();

				if (getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Weapon arme = shop.buy_weapon(id);
					setArgent(getArgent() - prix);
					setWeapon(arme);
					cout << "Vous venez d'acheter l'arme " << getWeapon().get_name() << endl;
				}
			}
			else if (shop.find_category(id) == DEFENSE) {
				index = shop.find_defense(id);
				prix = shop.get_list_defense().at(index).get_price_buy();

				if (getArgent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Defense defense = shop.buy_defense(id);
					setArgent(getArgent() - prix);
					setDefense(defense);
					cout << "Vous venez d'acheter la defense " << getDefense().get_name() << endl;
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
				Weapon arme;
				Defense def;

				switch (item_sell)
				{
				case 'A':
					if (getDefense().get_id() != -1) {
						prix = getWeapon().get_price_sell();
						setArgent(getArgent() + prix);
						shop.sell_weapon(getWeapon());
						setWeapon(arme);
						cout << "Vous venez de vendre votre arme\n";
					}
					else {
						cout << "Vous n'avez plus d'arme sur vous!\n";
					}
					
					break;
				case 'B':
					if (getDefense().get_id() != -1) {
						prix = getDefense().get_price_sell();
						setArgent(getArgent() + prix);
						shop.sell_defense(getDefense());
						setDefense(def);
						cout << "Vous venez de vendre votre defense\n";
					}
					else {
						cout << "Vous n'avez plus de defense sur vous!\n";
					}
					
					break;
				case 'C':

					break;
				default:
					cout << "Cette option n'existe! Veuillez entrer une option existante.\n";
					break;
				}
			} while (item_sell != 'C' && item_sell != 'B' && item_sell != 'A');
			cout << endl;

			break;
		case 'C':
			prix = getWeapon().get_price_buy() / 10;

			if (getArgent() < prix) {
				cout << "Vous n'avez pas assez d'argent pour am�liorer votre arme\n";
			}
			else {
				setArgent(getArgent() - prix);
				getWeapon().upgrade_weapon();
				cout << "Vous venez d'amelioer votre arme " << endl;
			}
			cout << endl;

			break;
		case 'D':
			nb_insult++;

			if (nb_insult < 3) {
				cout << "Vous venez d'insulter " << shop.get_seller().getName() << endl;
				cout << shop.get_seller().getName() << " commence a se facher\n";
			}
			else {
				cout << "Vous venez d'insulter " << shop.get_seller().getName() << endl;
				cout << shop.get_seller().getName() << " est fache et elle vous giffle\n";
				setHP(getHp() - shop.get_seller().getWeapon().get_attack()*nb_insult);
				cout << "Vous vous prenez " << shop.get_seller().getWeapon().get_attack()*nb_insult << " points de degats\n";
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
}

void Player::step() {
	hp_regen++;
	if (hp_regen == 10) {
		setHP(getHp() + 1);
		hp_regen = 0;
	}
}
