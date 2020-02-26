#include <cmath>
#include <iostream>
#include <sstream>

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

void Coord::show() const {
	std::cout << to_string() << std::endl;
}

std::string Coord::to_string() const {
	std::stringstream ss;
	ss << "Coord(" << m_x << ", " << m_y << ")";
	return ss.str();
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


Coord Coord::operator+(const int &other) const {
	return Coord(m_x + other, m_y + other);
}

Coord Coord::operator-(const Coord &other) const {
	return Coord(m_x - other.m_x, m_y - other.m_y);
}

Coord &Coord::operator=(const Coord &other) {
	m_x = other.m_x;
	m_y = other.m_y;
	return *this;
}

Coord &Coord::operator+=(const Coord &other) {
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}
