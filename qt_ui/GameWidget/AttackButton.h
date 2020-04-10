#pragma once


#include "GameButton.h"
#include "Direction.h"

class AttackButton : public GameButton{
public:
	AttackButton(Jeu* j, QString s, Direction d) : GameButton(j, s) {
		dir = d;
	}
	~AttackButton() {}

public slots:
	virtual void gameUpdate() {
		cout << jeu->attack(dir) << endl;
		emit gameUpdated();
	}

private:
	Direction dir;

};
