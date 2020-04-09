#pragma once
#include "TowerLabel.h"

void TowerLabel::gameUpdate() {
	setText("HP: " + jeu->tour().hp());
};