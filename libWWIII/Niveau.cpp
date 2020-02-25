#include <iostream>
#include "Niveau.h"

Niveau::Niveau(int niveau, int niveau_max) :
	m_niveau(niveau),
	m_niveau_max(niveau_max)
{
	int nb_niveaux = m_niveau_max - m_niveau;
	m_drop_prob_step = (m_max_drop_prob - m_base_drop_prob) / nb_niveaux;
	m_move_prob_step = (m_max_move_prob - m_base_move_prob) / nb_niveaux;

	std::random_device rd;
	m_randgen = std::default_random_engine(rd());
	m_unidist = std::uniform_int_distribution<int>(0, 100);
}

void Niveau::show() {
	std::cout << "Niveau " << m_niveau << std::endl;
	std::cout << "\tProbabilité de drop: " << drop_prob() << std::endl;
	std::cout << "\tProbabilité d'avancement: " << move_prob() << std::endl;
}

bool Niveau::should_drop() {
	return decide(drop_prob());
}

bool Niveau::should_move() {
	return decide(move_prob());
}

void Niveau::reset_bonus() {
	m_drop_bonus = 0;
	m_move_bonus = 0;
}

void Niveau::prochain() {
	if (m_niveau < m_niveau_max)
		m_niveau++;

	reset_bonus();
}

bool Niveau::decide(double prob) {
	return m_unidist(m_randgen) < prob;
}

/* Getters */

int Niveau::niveau() const {
	return m_niveau;
}

double Niveau::drop_prob() const {
	return m_base_drop_prob + m_drop_prob_step*double(m_niveau) + m_drop_bonus;
}

double Niveau::move_prob() const {
	return m_base_move_prob + m_move_prob_step*double(m_niveau) + m_move_bonus;
}

double Niveau::drop_bonus() const {
	return m_drop_bonus;
}

double Niveau::move_bonus() const {
	return m_move_bonus;
}

/* Setters */

void Niveau::set_niveau(int niveau) {
	m_niveau = niveau;
}

void Niveau::set_drop_bonus(double bonus) {
	m_drop_bonus = bonus;
}

void Niveau::set_move_bonus(double bonus) {
	m_move_bonus = bonus;
}

Niveau Niveau::operator+(const int level) {
	for (int i = 0; i < level; i++) {
		prochain();
	}
	return *this;
}
Niveau Niveau::operator=(const Niveau &niveau) {
	return niveau;
}
