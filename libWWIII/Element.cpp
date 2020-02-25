#include "Element.h"

void Element::set_position(Coord position) {
	m_position = position;
}

void Element::set_position(int x, int y) {
	m_position = Coord(x, y);
}

void Element::set_niveau(Niveau niveau) {
	m_niveau = niveau;
}

Coord Element::position() {
	return m_position;
}

Niveau Element::actualLevel() {
	return m_niveau;
}