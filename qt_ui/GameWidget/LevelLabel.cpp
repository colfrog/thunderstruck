#include 'LevelLabel.h'

LevelLabel::LevelLabel(Jeu* j) {
	jeu = j;
	gameUpdate();
};

void LevelLabel::gameUpdate() {
	setText("Niveau " + jeu->niveau_actuel());
};