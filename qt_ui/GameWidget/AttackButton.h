#pragma once

#include <string>

#include "GameButton.h"
#include "Direction.h"

class AttackButton : public GameButton{
public:
	AttackButton(Jeu* j, QString s, Direction dir);
	~GameButton() {}

public slots:
	virtual void gameUpdate() {}

signals:
	virtual void gameUpdated();

private
	Direction dir;

};
