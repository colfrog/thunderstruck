#pragma once
#include <QGraphicsView>

#include "../GameWidget/GameObject.h"

class GameGraphics : public GameObject {
	Q_OBJECT
public:
	GameGraphics(Jeu *j) :
		GameObject(j),
		m_scene(-400, -400, 800, 800),
		m_view(&m_scene)
	{
		m_view.show();
		jeu->run([this]() { gameUpdate(); });
	}
	~GameGraphics() {}

	QWidget *widget() {
		return &m_view;
	}

public slots:
	virtual void gameUpdate() {
		m_scene.advance();
		emit gameUpdated();
	}

private:
	QGraphicsScene m_scene;
	QGraphicsView m_view;
};
