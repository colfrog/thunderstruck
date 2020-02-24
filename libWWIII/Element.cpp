#include "Element.h"

void Element::set_position(Coord position) {
	m_position = position;
}

void Element::set_position(int x, int y) {
	m_position = Coord(x, y);
}

void Element::set_niveau(std::shared_ptr<Niveau> niveau) {
	m_niveau = niveau;
}
