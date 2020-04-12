#pragma once

#include <memory>
#include <vector>
#include "../Coord.h"
#include "../Niveau.h"
#include "../Items/Weapon.h"

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
	virtual void show() const = 0;

	virtual int attack(Element &elem, int mod = 0) = 0;
	virtual int damage(const Weapon &w, int mod = 0) = 0;

	const Coord &position() const;

	void set_position(Coord position);
	void set_position(int x, int y);

protected:
	Coord m_position;
	Jeu *m_jeu;
};
