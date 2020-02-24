#include <list>
#include <memory>
#include <functional>

#include "Element.h"
#include "Niveau.h"
#include "Tour.h"

class Jeu {
public:
	Jeu(int niveau_depart = 0, int niveau_max = 25, int f = 10);
	~Jeu();

	void run(std::function<void()> callback);
	void stop();
	bool running();

	int niveau_actuel() const;
	Tour &tour();

	void set_niveau(int niveau);

private:
	void prochain_niveau();

	bool m_running = false;

	const int m_frequence_jeu;
	const int m_niveau_depart;
	const int m_niveau_max;

	std::shared_ptr<Niveau> m_niveau; // Partagé avec les Elements
	std::list<Element *> m_elems;
	const std::unique_ptr<Tour> m_tour = std::unique_ptr<Tour>(new Tour());
};
