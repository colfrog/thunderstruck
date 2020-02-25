#include <cmath>
#include <iostream>
#include <assert.h>
#include <Tour.h>

using namespace std;

int main() {
	Tour tour(nullptr);

	assert(tour.get_player().get_name() == "" && tour.get_player().get_hp() == 100);


	return 0;
}
