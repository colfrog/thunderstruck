#pragma once
#include <QString>
#include <QLabel>

#include "GameLabel.h"

class TowerLabel : public GameLabel {
public:
	TowerLabel(Jeu* j, QString s) : GameLabel(j, s) { gameUpdate(s); }
	~TowerLabel() {}

public slots:
	virtual void gameUpdate(QString s) {
		label.setText(s + QString::number(jeu->tour().player().get_hp()));
	}
};
