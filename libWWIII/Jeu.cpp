#include <thread>
#include <chrono>

#include "Jeu.h"
#include "Lane.h"

Jeu::Jeu(int niveau_depart, int niveau_max, int f) :
	m_niveau_depart(niveau_depart),
	m_niveau_max(niveau_max),
	m_frequence_jeu(f)
{
	Niveau n = Niveau(m_niveau_depart, m_niveau_max);
	m_niveau = std::make_shared<Niveau>(n);

	for (int i = 0; i < 4; i++)
		m_elems.push_back(new Lane(DirTools::dirs[i]));
}

Jeu::~Jeu() {
	for (Element *elem : m_elems)
		delete elem;
}

void Jeu::run(std::function<void()> callback) {
	m_running = true;
	while (m_running) {
		for (Element *elem : m_elems)
			elem->step();

		callback();
		m_tour->step();

		std::this_thread::sleep_for(
			std::chrono::microseconds(1000000/m_frequence_jeu));
	}
}

bool Jeu::running() {
	return m_running;
}

void Jeu::stop() {
	m_running = false;
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

Tour &Jeu::tour() {
	return *m_tour;
}
