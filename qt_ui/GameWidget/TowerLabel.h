#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class TowerLabel : public GameLabel {
public:
	TowerLabel(Jeu* j) : GameLabel(j) { gameUpdate(); }
	~TowerLabel() {}

public slots:
	virtual void gameUpdate() {
		setText("HP: " + jeu->tour().hp());
	}
};
