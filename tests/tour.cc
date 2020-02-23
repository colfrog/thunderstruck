#include <cmath>
#include <iostream>
#include <assert.h>
#include <Tour.h>

using namespace std;

int main() {
	Tour tour;

	assert(tour.get_player().getName() == "" && tour.get_player().getHp() == 100);


	return 0;
}
