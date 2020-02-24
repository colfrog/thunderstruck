#include <cmath>
#include <iostream>
#include <assert.h>
#include <Player.h>

using namespace std;

int main() {
	Player player1, player2("Claudette");
	Weapon arme;
	Defense defense;

	assert(player1.getName() == "" && player2.getName() == "Claudette");

	//Test de la méthode enter_shop
	arme = player1.getShop().buy_weapon(WEAPON * pow(10, 2) + 04);
	defense = player1.getShop().buy_defense(DEFENSE * pow(10, 2) + 06);

	player2.setWeapon(arme);
	player2.setDefense(defense);

	player2.enter_shop();
	system("pause");/**/

	


	return 0;
}

