#include <Niveau.h>
#include <assert.h>
#include <iostream>

void test_prob() {
	/* 25% de chances de drop et de move */
	Niveau n(25, 25);

	int test_size = 1000;
	int moves = 0;
	int drops = 0;

	for (int i = 0; i < test_size; i++) {
		moves += n.should_move();
		drops += n.should_drop();
	}

	std::cout << "Moves: " << moves << ":" << test_size << std::endl;
	std::cout << "Drops: " << drops << ":" << test_size << std::endl;

	/* Je suis satisfait si le résultat est en bas de 30% */
	assert(moves < (test_size * 0.3) && drops < (test_size * 0.3));
}

int main() {
	test_prob();
	return 0;
}
