#include <cmath>
#include <iostream>
#include <assert.h>
#include <Elements/Tour.h>

using namespace std;

int main() {
	Tour tour(nullptr);

	assert(tour.player().get_name() == "" && tour.player().get_hp() == 100);
	assert(tour.hp() == 10 && tour.upgrade_tour(tour.player().get_argent()) == -1);


	return 0;
}
