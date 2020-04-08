#pragma once

#include <list>
#include <memory>
#include <functional>

#include "Niveau.h"
#include "Elements/Element.h"
#include "Elements/Tour.h"
#include "Elements/Lane.h"

class Jeu {
public:
	Jeu(std::string player_name,
		int niveau_depart = 0,
		int niveau_max = 25,
		int f = 10
	);
	~Jeu();

	void run(std::function<void()> callback);
	void stop();
	void step();
	bool running();
	void show() const;

	int niveau_actuel() const;
	Niveau &niveau();
	Tour &tour();
	Lane &lane(Direction dir);

	void set_niveau(int niveau);
	void add_element(Element *elem);

	int attack(Direction dir);

private:
	void prochain_niveau();

	bool m_running = false;

	const int m_frequence_jeu;
	const int m_niveau_depart;
	const int m_niveau_max;

	Niveau m_niveau;
	Tour m_tour;
	Lane m_left_lane, m_right_lane, m_up_lane, m_down_lane;
	std::list<Element *> m_elems;
};
