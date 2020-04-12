#include "Element.h"

void Element::set_position(Coord position) {
	m_position = position;
}

void Element::set_position(int x, int y) {
	m_position = Coord(x, y);
}

const Coord &Element::position() const {
	return m_position;
}
