#include <cmath>
#include <iostream>
#include <assert.h>
#include <Stats.h>

using namespace std;

int main() {
	Stats score;

	assert(score.get_score() == 0 && score.get_kills() == 0);

	score.set_kills(10);
	score.set_score(250);

	assert(score.get_score() == 250 && score.get_kills() == 10);

	score.set_stats(70, 70 * 25);

	assert(score.get_score() == 70 * 25 && score.get_kills() == 70);

	return 0;
}
