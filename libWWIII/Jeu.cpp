#include <thread>
#include <chrono>

#include "Jeu.h"

Jeu::Jeu(std::string player_name, int niveau_depart, int niveau_max, int f) :
	m_niveau_depart(niveau_depart),
	m_niveau_max(niveau_max),
	m_frequence_jeu(f),
	m_niveau(Niveau(m_niveau_depart, m_niveau_max)),
	m_tour(Tour(this)),
	m_left_lane(Lane(this, Direction::LEFT)),
	m_right_lane(Lane(this, Direction::RIGHT)),
	m_up_lane(Lane(this, Direction::UP)),
	m_down_lane(Lane(this, Direction::DOWN))
{
	Player *player = new Player(this, player_name);
	Weapon w(100);
	Defense d(1);
	player->set_weapon(w);
	player->set_defense(d);

	m_tour.set_player(player);
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

void Jeu::step() {
	m_spawned.clear();

	for (Element *elem : m_elems)
		elem->step();
}

void Jeu::run(std::function<void()> callback) {
	m_running = true;
	while (m_running) {
		step();
		callback();
		std::this_thread::sleep_for(
			std::chrono::microseconds(1000000/m_frequence_jeu)
		);
	}
}

bool Jeu::running() {
	return m_running;
}

void Jeu::stop() {
	m_running = false;
}

void Jeu::show() const {
	m_niveau.show();
	for (Element *elem : m_elems)
		elem->show();
}

void Jeu::declare_spawned(const Personnage *perso) {
	m_spawned.push_back(perso);
}

const std::list<const Personnage *> &Jeu::newly_spawned() const {
	return m_spawned;
}

int Jeu::niveau_actuel() const {
	return m_niveau.niveau();
}

Niveau &Jeu::niveau() {
	return m_niveau;
}

int Jeu::attack(Direction dir) {
	return m_tour.attack(lane(dir));
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

uint64_t Jeu::new_character_id() {
	return m_current_character_id++;
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
