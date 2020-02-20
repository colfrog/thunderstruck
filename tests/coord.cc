#include <Coord.h>
#include <assert.h>

void arithmetic_test() {
	Coord c1(2, 2);
	Coord c2(1, 1);
	Coord c3 = c1 - c2;
	Coord c4 = c1 + c2;

	assert(c3 == c2);
	assert(c4 == Coord(3, 3));
}

void distance_test() {
	Coord from = Coord(0, 0);
	Coord to = Coord(0, 1);
	assert(from.distance(to) == 1);
}

int main() {
	arithmetic_test();
	distance_test();
}
