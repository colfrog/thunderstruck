#include <Direction.h>
#include <assert.h>

void test_vectors() {
	Coord up(0, -1), down(0, 1), left(-1, 0), right(1, 0);
	assert(DirTools::vectors[Direction::UP] == up);
	assert(DirTools::vectors[Direction::DOWN] == down);
	assert(DirTools::vectors[Direction::LEFT] == left);
	assert(DirTools::vectors[Direction::RIGHT] == right);
}

void test_opposites() {
	assert(DirTools::opposites[Direction::UP] == Direction::DOWN);
	assert(DirTools::opposites[Direction::DOWN] == Direction::UP);
	assert(DirTools::opposites[Direction::LEFT] == Direction::RIGHT);
	assert(DirTools::opposites[Direction::RIGHT] == Direction::LEFT);
}

int main() {
	test_vectors();
	test_opposites();
}
