#pragma once
#include <QGraphicsView>
#include <thread>

#include "../GameWidget/GameObject.h"
#include "TowerItem.h"
#include "LaneItem.h"
#include "CharacterItem.h"
#include "PlayerItem.h"
#include "Palette.h"

class GameBackground : public QGraphicsItem {
public:
	GameBackground() {
		setVisible(true);
	}

	QRectF boundingRect() const override {
		return QRectF(-400, -400, 800, 800);
	}

	void paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option,
		QWidget *widget)
	override
	{
		painter->fillRect(-400, -400, 800, 800, m_background);
	}

private:
	const QColor m_background = PALETTE(PURPLE_DARKER);
};

class GameGraphics : public GameObject {
	Q_OBJECT
public:
	GameGraphics(Jeu *j) :
		GameObject(j),
		m_scene(-400, -400, 800, 800),
		m_view(&m_scene)
	{
		m_scene.addItem(new GameBackground());
		m_view.show();

		m_gameThread = new std::thread(
			[this](std::function<void()> f) { jeu->run(f); },
			[this]() { gameUpdate(); }
		);
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
	std::thread *m_gameThread;
	QGraphicsScene m_scene;
	QGraphicsView m_view;
};
