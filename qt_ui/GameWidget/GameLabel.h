#pragma once
#include <QString>
#include <QLabel>

#include "GameObject.h"

class GameLabel : public GameObject {
public:
	GameLabel(Jeu *j, QString s = "") : GameObject(j), label(s) {
		gameUpdate();
	}
	virtual ~GameLabel() {}

	virtual QWidget *widget() {
		return &label;
	}

public slots:
	virtual void gameUpdate() {}

private:
	QLabel label;
};
