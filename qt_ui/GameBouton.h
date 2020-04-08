#pragma once

#include <string>
#include <QPushButton>

#include "GameObject.h"

class GameBouton : public GameObject, public QPushButton {
public:
	GameBouton(QString);
	~GameBouton();

public slots:
	void update(QString s);

signals:
	void updated();

};