#pragma once

#include <memory>

#include "Coord.h"
#include "Niveau.h"

class Element {
public:
	Element(Coord position) : m_position(position) {}
	Element(int x, int y) : m_position(Coord(x, y)) {}
	Element() {}
	virtual ~Element() {}

	virtual void step() = 0;

	Coord position();

	void set_position(Coord position);
	void set_position(int x, int y);
	void set_niveau(std::shared_ptr<Niveau> m_niveau);

protected:
	Coord m_position;
	std::shared_ptr<Niveau> m_niveau;
};
