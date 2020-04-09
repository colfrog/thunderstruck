#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class LevelLabel : public GameLabel {
public:
	LevelLabel(Jeu* j) : GameLabel(j) {}
	~LevelLabel() {}

	virtual void gameUpdate();

private:
	QString m_text;
	Jeu *jeu;
};