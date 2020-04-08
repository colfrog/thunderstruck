#pragma once
#include <QAction>
#include "GameObject.h"
#include "Jeu.h"

class GameAction : public GameObject {
public:
	GameAction(Jeu* j) : GameObject(j) {}
	~GameAction() {}

public slots:
	virtual void gameUpdate() {
		jeu->step();
		gameUpdated();
	};
};
