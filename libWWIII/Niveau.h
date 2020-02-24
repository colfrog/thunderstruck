#pragma once

#include <random>

/*
 * Choses à rajouter éventuellement:
 * 	- Facteur de drop (pour dropper plus d'or)
 * 	- Facteur de dégât (pour faire plus de dégât)
 * 	- Probabilité de spawn
 */

class Niveau {
public:
	Niveau(int niveau_depart = 0, int niveau_max = 25);
	~Niveau() {}

	void show();
	bool should_drop();
	bool should_move();
	void reset_bonus();
	void prochain();

	/* Getters */
	int niveau() const;
	double drop_prob() const;
	double move_prob() const;
	double drop_bonus() const;
	double move_bonus() const;

	/* Setters */
	void set_niveau(int niveau);
	void set_drop_bonus(double bonus);
	void set_move_bonus(double bonus);

private:
	bool decide(double prob);

	int m_niveau;
	int m_niveau_max;

	const double m_base_drop_prob = 10;
	const double m_base_move_prob = 10;
	const double m_max_drop_prob = 70;
	const double m_max_move_prob = 100;
	double m_drop_prob_step;
	double m_move_prob_step;

	double m_drop_bonus = 0;
	double m_move_bonus = 0;

	std::default_random_engine m_randgen;
	std::uniform_int_distribution<int> m_unidist;
};
