#include <Niveau.h>
#include <assert.h>
#include <iostream>

void test_prob() {
	/* 10% de chances de drop et de move, niveaux de 1 à 25 */
	Niveau n(0, 25);

	int test_size = 1000;
	int moves = 0;
	int drops = 0;

	for (int i = 0; i < test_size; i++) {
		moves += n.should_move();
		drops += n.should_drop();
	}

	n.show();
	std::cout << "Moves: " << moves << ":" << test_size << std::endl;
	std::cout << "Drops: " << drops << ":" << test_size << std::endl;

	/* Je suis satisfait si le résultat est en bas de 12% */
	assert(moves < (test_size * 0.12) && drops < (test_size * 0.12));
	/* Je suis satisfait si le résultat est en haut de 8% */
	assert(moves > (test_size * 0.08) && drops > (test_size * 0.08));
}

void test_progression() {
	Niveau n(0, 100);
	do {
		n.show();
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
