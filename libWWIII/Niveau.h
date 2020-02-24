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
	Niveau(
		int niveau_depart = 0,
		int niveau_max = 25,
		double dp = 10,
		double mp = 10
	);
	~Niveau() {}

	void show();
	bool should_drop();
	bool should_move();
	void update_probs();
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
	double calc_drop_prob() const;
	double calc_move_prob() const;

	int m_niveau;
	int m_niveau_max;

	double m_drop_prob;
	double m_move_prob;
	double m_drop_prob_step;
	double m_move_prob_step;

	const double m_base_drop_prob;
	const double m_base_move_prob;
	const double m_max_drop_prob = 70;
	const double m_max_move_prob = 100;

	double m_drop_bonus = 0;
	double m_move_bonus = 0;

	std::default_random_engine m_randgen;
	std::uniform_int_distribution<int> m_unidist;
};
