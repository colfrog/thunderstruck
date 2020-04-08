#pragma once
#include <QString>
#include <QLabel>

#include "GameObject.h"

class GameLabel : public GameObject, public QLabel {
public:
	GameLabel(QString);
	~GameLabel();

public slots:
	void update(QString);

signals:
	void updated();

};