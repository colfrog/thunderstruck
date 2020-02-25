#include <iostream>

#include "Shop.h"
#include "Jeu.h"

Tour *tour;

void callback() {
	std::cout << tour->get_player().get_hp() << std::endl;
}

int main() {
	Jeu jeu("John Doe");
	tour = &jeu.tour();
	jeu.run(callback);

	return 0;
}
