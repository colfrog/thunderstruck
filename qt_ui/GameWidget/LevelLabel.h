#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class LevelLabel : public GameLabel {
public:
	LevelLabel(Jeu* j) : GameLabel(j) { gameUpdate(); }
	~LevelLabel() {}

public slots:
	virtual void gameUpdate() {
		setText("Niveau " + jeu->niveau_actuel());
	}
};
