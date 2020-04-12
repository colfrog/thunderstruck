#pragma once
#include <QGraphicsItem>

#include <Elements/Personnage.h>
#include "Palette.h"

class CharacterItem : public QGraphicsItem {
public:
	CharacterItem(const Personnage *p) :
		m_char(p),
		m_pos(p->position())
	{}
	~CharacterItem() {};

	QRectF boundingRect() const override {
		return QRectF(2*m_pos.x() - 2, 2*m_pos.y() - 2, 4, 4);
	}

	void paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option,
		QWidget *widget)
	override
	{
		painter->fillRect(2*m_pos.x() - 2, 2*m_pos.y() - 2, 4, 4, m_darkGreen);
	}

private:
	const Personnage *m_char;
	const Coord &m_pos;

	const QColor m_darkGreen = PALETTE(GREEN_DARK);
};
