#include "Stats.h"

Stats::Stats()
{
	m_score = 0;
	m_nb_ennemi_dead = 0;
}

Stats::~Stats()
{
}

int Stats::get_score() {
	return m_score;
}
int Stats::get_nb_ennemi_dead() {
	return m_nb_ennemi_dead;
}

void Stats::set_score(int score) {
	m_score = score;
}
int Stats::set_nb_ennemi_dead(int nb_ennemi_dead) {
	m_nb_ennemi_dead = nb_ennemi_dead;
}

void Stats::afficher() {
	cout << "======================================================================\n";
	cout << "Score : " << m_score << "\n";
	cout << "Nombre d'ennemis tues : " << m_nb_ennemi_dead << endl;
	cout << "======================================================================\n";
}