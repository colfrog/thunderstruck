#pragma once
#include "LevelLabel.h"

void LevelLabel::gameUpdate() {
	setText("Niveau " + jeu->niveau_actuel());
};