#pragma once
#include <QAction>
#include "GameObject.h"
#include "Jeu.h"



class GameAction : public GameObject {
public:
	GameAction(Jeu* j) { jeu = j }
	~GameAction() {}

public slots:
	void update() { jeu->step };

signals:
	void updated() {};

private:
	Jeu* jeu;

};