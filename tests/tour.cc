#include <cmath>
#include <iostream>
#include <assert.h>
#include <Tour.h>

using namespace std;

int main() {
	Tour tour(nullptr);

	assert(tour.player().get_name() == "" && tour.player().get_hp() == 100);
	assert(tour.hp() == 10 && tour.upgrade_tour() == -1);


	return 0;
}
