#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class LevelLabel : public GameLabel {
public:
	LevelLabel(Jeu* j, QString s) : GameLabel(j, s) { gameUpdate(s); }
	~LevelLabel() {}

public slots:
	virtual void gameUpdate(QString s) {
		setText(s + QString::number(jeu->niveau_actuel()));
	}
};
