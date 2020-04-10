#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class LevelLabel : public GameLabel {
public:
	LevelLabel(Jeu* j, QString s) : GameLabel(j, s) { gameUpdate(); }
	~LevelLabel() {}

public slots:
	virtual void gameUpdate() {
		label.setText(text + QString::number(jeu->niveau_actuel()));
	}
};
