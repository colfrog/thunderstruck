#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class TowerLabel : public GameLabel {
public:
	TowerLabel(Jeu* j, QString s) : GameLabel(j, s) { gameUpdate(); }
	~TowerLabel() {}

public slots:
	virtual void gameUpdate() {
		label.setText(text + QString::number(jeu->tour().player().get_hp()));
	}
};
