#pragma once
#include <QWidget>
#include "Jeu.h"


class GameObject : public QObject {
public:
	GameObject(Jeu* j) : jeu(j) {}
	virtual ~GameObject() {}

	virtual QWidget *widget() { return NULL; }

public slots:
	virtual void gameUpdate() = 0;

signals:
	virtual void gameUpdated() {}

protected:
	Jeu* jeu;
};
