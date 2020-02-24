#pragma once

#include <map>

#include "Coord.h"

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

namespace DirTools {
	/* Vecteurs de déplacement */
	const std::map<Direction, Coord> vectors = {
		{Direction::UP, Coord(0, -1)},
		{Direction::DOWN, Coord(0, 1)},
		{Direction::LEFT, Coord(-1, 0)},
		{Direction::RIGHT, Coord(1, 0)}
	};

	/* Opposés */
	const std::map<Direction, Direction> opposites = {
		{Direction::UP, Direction::DOWN},
		{Direction::DOWN, Direction::UP},
		{Direction::LEFT, Direction::RIGHT},
		{Direction::RIGHT, Direction::LEFT}
	};

	/* Vers la gauche */
	const std::map<Direction, Direction> lefts = {
		{Direction::UP, Direction::LEFT},
		{Direction::DOWN, Direction::RIGHT},
		{Direction::LEFT, Direction::DOWN},
		{Direction::RIGHT, Direction::UP}
	};

	/* Vers la droite */
	const std::map<Direction, Direction> rights = {
		{Direction::UP, Direction::RIGHT},
		{Direction::DOWN, Direction::LEFT},
		{Direction::LEFT, Direction::UP},
		{Direction::RIGHT, Direction::DOWN}
	};
};
