#include <cmath>
#include <iostream>
#include <assert.h>
#include <Stats.h>

using namespace std;

int main() {
	Stats score;

	assert(score.get_score() == 0 && score.get_nb_ennemi_dead() == 0);

	score.set_nb_ennemi_dead(10);
	score.set_score(250);

	assert(score.get_score() == 250 && score.get_nb_ennemi_dead() == 10);

	return 0;
}