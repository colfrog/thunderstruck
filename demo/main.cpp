#include <iostream>

#include "Shop.h"
#include "Jeu.h"

Tour *tour;

void callback() {
	std::cout << tour->get_player().getHp() << std::endl;
}

int main() {
	Jeu jeu;
	tour = &jeu.tour();
	jeu.run(callback);

	return 0;
}
