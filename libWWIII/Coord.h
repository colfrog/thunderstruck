#pragma once

class Coord {
public:
	Coord(int x, int y) : m_x(x), m_y(y) {}
	Coord() {}
	~Coord() {}

	int x();
	int y();
	void set_coords(int x, int y);

	void show();
	int distance(const Coord &) const;

	bool operator==(const Coord &) const;
	Coord operator*(const int) const;
	Coord operator+(const Coord &) const;
	Coord operator+(const int &) const;
	Coord operator-(const Coord &) const;

	Coord &operator=(const Coord &);
	Coord &operator+=(const Coord &);

private:
	int m_x;
	int m_y;
};
