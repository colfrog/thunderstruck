#include <list>
#include <memory>

#include "Niveau.h"

class Jeu {
public:
	Jeu(int niveau_depart = 0, int niveau_max = 25, int f = 2);
	~Jeu();

	int niveau_actuel() const;
	void set_niveau(int niveau);

private:
	void prochain_niveau();

	const double m_base_drop_prob = 10;
	const double m_base_move_prob = 10;

	const int m_frequence_jeu;
	const int m_niveau_depart;
	const int m_niveau_max;
	std::shared_ptr<Niveau> m_niveau; // Partagé avec les Elements
};
