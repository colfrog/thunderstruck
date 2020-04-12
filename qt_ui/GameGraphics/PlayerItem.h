#pragma once
#include "CharacterItem.h"

class PlayerItem : public CharacterItem {
public:
	void paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option,
		QWidget *widget)
	override
	{
		painter->fillRect(-2, -2, 4, 4, m_orange);
		painter->fillRect(-2, -2, 1, 4, m_darkPurple);
		painter->fillRect(2, -2, 1, 4, m_darkPurple);
		painter->fillRect(-2, 2, 1, 4, m_darkPurple);
	}

private:
	const QColor m_orange = PALETTE(ORANGE);
	const QColor m_darkPurple = PALETTE(PURPLE_DARKER);
};
