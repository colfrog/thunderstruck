#include "Jeu.h"
#include "Lane.h"

Jeu::Jeu(int niveau_depart, int niveau_max, int f) :
	m_niveau_depart(niveau_depart),
	m_niveau_max(niveau_max),
	m_frequence_jeu(f)
{
	Niveau n = Niveau(m_niveau_depart, m_niveau_max);
	m_niveau = std::make_shared<Niveau>(n);

	m_tour = std::unique_ptr<Tour>(new Tour());

	for (int i = 0; i < 4; i++)
		m_elems.push_back(std::unique_ptr<Lane>(new Lane(DirTools::dirs[i])));
}

Jeu::~Jeu() {
}

int Jeu::niveau_actuel() const {
	return m_niveau->niveau();
}

void Jeu::set_niveau(int niveau) {
	m_niveau->set_niveau(niveau);
}

void Jeu::prochain_niveau() {
	m_niveau->prochain();
}
