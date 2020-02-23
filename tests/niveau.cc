#include <Niveau.h>
#include <assert.h>
#include <iostream>

void test_prob() {
	/* 25% de chances de drop et de move, niveaux de 1 à 25 */
	Niveau n(1, 25, 25, 25);

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

void test_progression() {
	Niveau n(0, 100, 10, 10);
	do {
		std::cout << "Niveau " << n.niveau() << std::endl;
		std::cout << "\tProbabilité de drop: " << n.drop_prob() << std::endl;
		std::cout << "\tProbabilité d'avancement: " << n.move_prob() << std::endl;
		n.prochain();
	} while (n.niveau() < 100);

	assert(n.drop_prob() >= 0 && n.drop_prob() <= 100);
	assert(n.move_prob() >= 0 && n.move_prob() <= 100);
}

int main() {
	test_prob();
	test_progression();
	return 0;
}
