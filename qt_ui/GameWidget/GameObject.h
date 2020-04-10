#pragma once
#include "Jeu.h"
//#include "GameWidget.h"
#include <QObject>


class GameObject : public QObject {
	Q_OBJECT
public:
	GameObject(Jeu* j) : jeu(j) {}
	virtual ~GameObject() {}

public slots:
	virtual void gameUpdate() = 0;

signals:
	void gameUpdated();

protected:
	Jeu* jeu;
};
