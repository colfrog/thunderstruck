#pragma once
#include "Jeu.h"
//#include "GameWidget.h"


class GameObject {
public:
	GameObject(Jeu* j) { jeu = j; }
	GameObject() {}
	virtual ~GameObject() {}

public slots:
	virtual void update(QString s) = 0;

signals:
	virtual void updated() = 0;

private:
	Jeu* jeu;


};