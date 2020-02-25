#include <cmath>
#include <iostream>

#include "Coord.h"

int Coord::x() {
	return m_x;
}

int Coord::y() {
	return m_y;
}

void Coord::set_coords(int x, int y) {
	m_x = x;
	m_y = y;
}

void Coord::show() {
	std::cout << "Coord(" << m_x << ", " << m_y << ")" << std::endl;
}

int Coord::distance(const Coord &other) const {
	int x = m_x - other.m_x;
	int y = m_y - other.m_y;
	return std::sqrt(x*x + y*y);
}

bool Coord::operator==(const Coord &other) const {
	return m_x == other.m_x && m_y == other.m_y;
}

Coord Coord::operator*(const int factor) const {
	return Coord(factor*m_x, factor*m_y);
}

Coord Coord::operator+(const Coord &other) const {
	return Coord(m_x + other.m_x, m_y + other.m_y);
}

Coord Coord::operator-(const Coord &other) const {
	return Coord(m_x - other.m_x, m_y - other.m_y);
}

Coord Coord::operator=(const Coord &other) const {
	return other;
}
