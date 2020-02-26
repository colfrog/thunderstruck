#pragma once

#include <memory>
#include <vector>
#include "Coord.h"
#include "Niveau.h"

class Jeu;

class Element {
public:
	Element(Jeu *jeu, Coord position = Coord(0, 0)) :
		m_jeu(jeu),
		m_position(position)
	{}
	Element() {}
	virtual ~Element() {}

	virtual void step() = 0;

	Coord position() const;

	void set_position(Coord position);
	void set_position(int x, int y);

protected:
	Coord m_position;
	Jeu *m_jeu;
};
