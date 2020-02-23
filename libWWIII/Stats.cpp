#include "Stats.h"

Stats::Stats()
{
	m_score = 0;
	m_kills = 0;
}

Stats::~Stats()
{
}

int Stats::get_score() {
	return m_score;
}
int Stats::get_kills() {
	return m_kills;
}

void Stats::set_score(int score) {
	m_score = score;
}
void Stats::set_kills(int kills) {
	m_kills = kills;
}

void Stats::afficher() {
	cout << "======================================================================" << endl;
	cout << "Score : " << m_score << endl;
	cout << "Nombre d'ennemis tues : " << m_kills << endl;
	cout << "======================================================================" << endl;
}
