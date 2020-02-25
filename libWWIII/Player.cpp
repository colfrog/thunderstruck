
#include "Player.h"

Player::Player(const Jeu *jeu, string n) : Personnage(jeu, n), m_shop(jeu) {}
Player::~Player() {}

Stats Player::get_stats() {
	return m_stats;
}
void Player::set_stats(Stats st) {
	m_stats = st;
}

int Player::get_argent() {
	return m_argent;
}
void Player::set_argent(int arg) {
	m_argent = arg;
}

Shop Player::get_shop() {
	return m_shop;
}
void Player::set_shop(Shop s) {
	m_shop = s;
}

void Player::enter_shop() {
	cout << "Bienvenue dans mon magasion!\n";
	cout << "Mon nom est " << m_shop.get_seller().get_name() << endl;
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
			m_shop.show_list();

			cout << "Entrer l'id de l'item que vous voulez acheter\n";

			cin >> id;

			if (m_shop.find_category(id) == POTION) {
				index = m_shop.find_potion(id);
				prix = m_shop.get_list_potion().at(index).get_price_buy();

				if (get_argent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Potion potion = m_shop.buy_potion(id);
					set_argent(get_argent() - prix);
					if (get_hp() + potion.get_hp_restore() > 100) {
						set_hp(100);
					}
					else {
						set_hp(get_hp() + potion.get_hp_restore());
					}
					cout << "Vous venez d'acheter la potion " << potion.get_name() << endl;
				}
			}
			else if (m_shop.find_category(id) == WEAPON) {
				index = m_shop.find_weapon(id);
				prix = m_shop.get_list_weapon().at(index).get_price_buy();

				if (get_argent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Weapon arme = m_shop.buy_weapon(id);
					set_argent(get_argent() - prix);
					set_weapon(arme);
					cout << "Vous venez d'acheter l'arme " << get_weapon().get_name() << endl;
				}
			}
			else if (m_shop.find_category(id) == DEFENSE) {
				index = m_shop.find_defense(id);
				prix = m_shop.get_list_defense().at(index).get_price_buy();

				if (get_argent() < prix) {
					cout << "Vous n'avez pas assez d'argent pour acheter cet item\n";
				}
				else {
					Defense defense = m_shop.buy_defense(id);
					set_argent(get_argent() - prix);
					set_defense(defense);
					cout << "Vous venez d'acheter la defense " << get_defense().get_name() << endl;
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
					if (get_defense().get_id() != -1) {
						prix = get_weapon().get_price_sell();
						set_argent(get_argent() + prix);
						m_shop.sell_weapon(get_weapon());
						set_weapon(arme);
						cout << "Vous venez de vendre votre arme\n";
					}
					else {
						cout << "Vous n'avez plus d'arme sur vous!\n";
					}
					
					break;
				case 'B':
					if (get_defense().get_id() != -1) {
						prix = get_defense().get_price_sell();
						set_argent(get_argent() + prix);
						m_shop.sell_defense(get_defense());
						set_defense(def);
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
			prix = get_weapon().get_price_buy() / 10;

			if (get_argent() < prix) {
				cout << "Vous n'avez pas assez d'argent pour am�liorer votre arme\n";
			}
			else {
				set_argent(get_argent() - prix);
				get_weapon().upgrade_weapon();
				cout << "Vous venez d'amelioer votre arme " << endl;
			}
			cout << endl;

			break;
		case 'D':
			nb_insult++;

			if (nb_insult < 3) {
				cout << "Vous venez d'insulter " << m_shop.get_seller().get_name() << endl;
				cout << m_shop.get_seller().get_name() << " commence a se facher\n";
			}
			else {
				cout << "Vous venez d'insulter " << m_shop.get_seller().get_name() << endl;
				cout << m_shop.get_seller().get_name() << " est fache et elle vous giffle\n";
				set_hp(get_hp() - m_shop.get_seller().get_weapon().get_attack()*nb_insult);
				cout << "Vous vous prenez " << m_shop.get_seller().get_weapon().get_attack()*nb_insult << " points de degats\n";
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
	m_hp_regen++;
	if (m_hp_regen == 10 && get_hp() > 0 && get_hp() < 100) {
		set_hp(get_hp() + 1);
		m_hp_regen = 0;
	}
}
