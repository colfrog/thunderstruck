#pragma once
#include <QAction>
#include "GameObject.h"
#include "Jeu.h"

class GameAction : public GameObject {
	Q_OBJECT
public:
	GameAction(Jeu* j) : GameObject(j) {}
	virtual ~GameAction() {}

public slots:
	virtual void gameUpdate() {
		jeu->step();
		emit gameUpdated();
	};
};
