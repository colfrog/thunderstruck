#include <list>
#include <memory>

#include "Element.h"
#include "Niveau.h"
#include "Tour.h"

class Jeu {
public:
	Jeu(int niveau_depart = 0, int niveau_max = 25, int f = 2);
	~Jeu();

	int niveau_actuel() const;
	void set_niveau(int niveau);

	Tour &tour();

private:
	void prochain_niveau();

	const int m_frequence_jeu;
	const int m_niveau_depart;
	const int m_niveau_max;

	std::shared_ptr<Niveau> m_niveau; // Partagé avec les Elements
	std::list<std::unique_ptr<Element>> m_elems;
	std::unique_ptr<Tour> m_tour = nullptr;
};
