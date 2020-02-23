#include "Niveau.h"

Niveau::Niveau(double dp, double mp) : drop_prob(dp), move_prob(mp) {
	std::random_device rd;
	m_randgen = std::default_random_engine(rd());
	m_unidist = std::uniform_int_distribution<int>(0, 100);
}

bool Niveau::should_drop() {
	return decide(drop_prob + m_drop_bonus);
}

bool Niveau::should_move() {
	return decide(move_prob + m_move_bonus);
}

bool Niveau::decide(double prob) {
	return m_unidist(m_randgen) < prob;
}

double Niveau::drop_bonus() const {
	return m_drop_bonus;
}

double Niveau::move_bonus() const {
	return m_move_bonus;
}

void Niveau::set_drop_bonus(double bonus) {
	m_drop_bonus = bonus;
}

void Niveau::set_move_bonus(double bonus) {
	m_move_bonus = bonus;
}
