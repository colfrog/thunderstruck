#pragma once
#include "TowerLabel.h"

TowerLabel::TowerLabel(Jeu* j) {
	jeu = j;
	gameUpdate();
};

void TowerLabel::gameUpdate() {
	setText("Tour: " + jeu->tour()->hp() + "HP");
};