#pragma once


#include "GameButton.h"
#include "Direction.h"

class AttackButton : public GameButton{
public:
	AttackButton(Jeu* j, QString s, Direction d);
	~AttackButton() {}

public slots:
	virtual void gameUpdate();

private:
	Direction dir;

};
