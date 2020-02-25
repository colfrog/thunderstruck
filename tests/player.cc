#include <cmath>
#include <iostream>
#include <assert.h>
#include <Player.h>

using namespace std;

int main() {
	Player player1, player2("Claudette");
	Weapon arme;
	Defense defense;

	assert(player1.get_name() == "" && player2.get_name() == "Claudette");

	//Test de la méthode enter_shop
	arme = player1.get_shop().buy_weapon(WEAPON * pow(10, 2) + 04);
	defense = player1.get_shop().buy_defense(DEFENSE * pow(10, 2) + 06);

	player2.set_weapon(arme);
	player2.set_defense(defense);

	player2.enter_shop();
	return 0;
}

