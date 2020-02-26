#include <thread>
#include <chrono>

#include "Jeu.h"

Jeu::Jeu(std::string player_name, int niveau_depart, int niveau_max, int f) :
	m_niveau_depart(niveau_depart),
	m_niveau_max(niveau_max),
	m_frequence_jeu(f),
	m_niveau(Niveau(m_niveau_depart, m_niveau_max)),
	m_tour(Tour(this, player_name)),
	m_left_lane(Lane(this, Direction::LEFT)),
	m_right_lane(Lane(this, Direction::RIGHT)),
	m_up_lane(Lane(this, Direction::UP)),
	m_down_lane(Lane(this, Direction::DOWN))
{
	m_elems.push_back(&m_tour);
	m_elems.push_back(&m_up_lane);
	m_elems.push_back(&m_down_lane);
	m_elems.push_back(&m_left_lane);
	m_elems.push_back(&m_right_lane);
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
	return m_niveau.niveau();
}

Niveau &Jeu::niveau() {
	return m_niveau;
}

Lane &Jeu::lane(Direction dir) {
	switch (dir) {
		case Direction::UP:
			return m_up_lane;
		case Direction::DOWN:
			return m_down_lane;
		case Direction::LEFT:
			return m_left_lane;
		case Direction::RIGHT:
			return m_right_lane;
		default:
			return m_up_lane;
	}
}

void Jeu::set_niveau(int niveau) {
	m_niveau.set_niveau(niveau);
}

void Jeu::add_element(Element *elem) {
	m_elems.push_back(elem);
}

void Jeu::prochain_niveau() {
	m_niveau.prochain();
}

Tour &Jeu::tour() {
	return m_tour;
}
