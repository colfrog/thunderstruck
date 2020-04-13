#pragma once

#include <iostream>
#include <QPushButton>

#include "GameObject.h"

class GameButton : public GameObject {
	Q_OBJECT
public:
	GameButton(Jeu *j, QString s) : GameObject(j), button(s) {
		QObject::connect(&button, SIGNAL(clicked()), this, SLOT(gameUpdate()));
	}
	virtual ~GameButton() {}

	virtual QWidget *widget() {
		return &button;
	}

public slots:
	virtual void gameUpdate() {
		emit gameUpdated();
	}

	virtual void shortCutActivated() {
		emit gameUpdated();
	}

protected:
	QPushButton button;
};
