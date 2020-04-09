#pragma once
#include "Jeu.h"

class GameObject {
public:
	GameObject(Jeu* j) : jeu(j) {}
	virtual ~GameObject() {}

public slots:
	virtual void gameUpdate() = 0;

signals:
	virtual void gameUpdated() {}

protected:
	Jeu* jeu;
};
