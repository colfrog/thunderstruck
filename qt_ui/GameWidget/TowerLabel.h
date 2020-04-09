#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class TowerLabel : public GameLabel {
public:
	TowerLabel(Jeu* j) : GameLabel(j) {}
	~TowerLabel() {}

	virtual void gameUpdate();

private:
	QString m_text;
	Jeu *jeu;
};