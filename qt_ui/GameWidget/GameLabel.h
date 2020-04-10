#pragma once
#include <QString>
#include <QLabel>

#include "GameObject.h"

class GameLabel : public GameObject {
public:
	GameLabel(Jeu *j, QString s = "") : GameObject(j), label(s), text(s) {
		gameUpdate();
	}
	virtual ~GameLabel() {}

	virtual QWidget *widget() {
		return &label;
	}

public slots:
	virtual void gameUpdate() {}

protected:
	QLabel label;
	QString text;
};
