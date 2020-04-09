#pragma once
#include <QString>
#include <QLabel>

#include "GameObject.h"

class GameLabel : public GameObject, public QLabel {
public:
	GameLabel(Jeu *j) : GameObject(j) { gameUpdate(); }
	~GameLabel() {}

private:
	QString m_text;
};
