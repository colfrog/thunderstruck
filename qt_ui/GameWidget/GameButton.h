#pragma once

#include <string>
#include <QPushButton>

#include "GameObject.h"

class GameButton : public GameObject, public QPushButton {
public:
	GameButton(Jeu *j, QString s) : GameObject(j), QPushButton(s) {}
	~GameButton() {}

public slots:
	virtual void gameUpdate() {}
};
