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
	/*player2.setWeapon(arme);
	player2.setDefense(defense);

	player2.enter_shop();
	system("pause");/**/

	


	return 0;
}

