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
	/* Liste des directions */
	static Direction dirs[] = {
		Direction::UP, Direction::DOWN,
		Direction::LEFT, Direction::RIGHT
	};

	static std::map<Direction, std::string> dir_names = {
		{Direction::UP, "haut"},
		{Direction::DOWN, "bas"},
		{Direction::LEFT, "gauche"},
		{Direction::RIGHT, "droite"}
	};

	/* Vecteurs de déplacement */
	static std::map<Direction, Coord> vectors = {
		{Direction::UP, Coord(0, -1)},
		{Direction::DOWN, Coord(0, 1)},
		{Direction::LEFT, Coord(-1, 0)},
		{Direction::RIGHT, Coord(1, 0)}
	};

	/* Opposés */
	static std::map<Direction, Direction> opposites = {
		{Direction::UP, Direction::DOWN},
		{Direction::DOWN, Direction::UP},
		{Direction::LEFT, Direction::RIGHT},
		{Direction::RIGHT, Direction::LEFT}
	};

	/* Vers la gauche */
	static std::map<Direction, Direction> lefts = {
		{Direction::UP, Direction::LEFT},
		{Direction::DOWN, Direction::RIGHT},
		{Direction::LEFT, Direction::DOWN},
		{Direction::RIGHT, Direction::UP}
	};

	/* Vers la droite */
	static std::map<Direction, Direction> rights = {
		{Direction::UP, Direction::RIGHT},
		{Direction::DOWN, Direction::LEFT},
		{Direction::LEFT, Direction::UP},
		{Direction::RIGHT, Direction::DOWN}
	};
};
