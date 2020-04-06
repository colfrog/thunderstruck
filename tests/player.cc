#include <cmath>
#include <iostream>
#include <assert.h>
#include <Elements/Player.h>
#include <Jeu.h>

using namespace std;

int main() {
	Jeu *jeu = new Jeu("Claudette");
	Player player1(jeu, ""), player2(jeu, "Claudette");
	Weapon arme;
	Defense defense;

	assert(player1.get_name() == "" && player2.get_name() == "Claudette");

	//Test de la m�thode enter_shop
	arme = player1.get_shop().buy_weapon(WEAPON * pow(10, 2) + 04);
	defense = player1.get_shop().buy_defense(DEFENSE * pow(10, 2) + 06);

	player2.set_weapon(arme);
	player2.set_defense(defense);
	player2.set_argent(1000);

	/*
	 * D�commenter pour tester le shop mais ne pas commit
	 * pour ne pas bloquer l'ex�cution du test automatique
	 */
	player2.enter_shop();/**/
	
	return 0;
}

