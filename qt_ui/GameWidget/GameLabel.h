#pragma once
#include <QString>
#include <QLabel>

#include "GameObject.h"

class GameLabel : public GameObject, public QLabel {
public:
	GameLabel(Jeu *j, QString s = "") : GameObject(j), QLabel(s) {}
	~GameLabel() {}

public slots:
	virtual void gameUpdate() {}
};
