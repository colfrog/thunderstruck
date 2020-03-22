#include <iostream>

#include <Direction.h>
#include <Shop.h>
#include <Jeu.h>

Jeu *jeup;
Tour *tourp;

void callback() {
	jeup->show();
}

int main() {
	Jeu jeu("John Doe");
	jeup = &jeu;
	tourp = &jeu.tour();
	jeu.run(callback);

	return 0;
}
