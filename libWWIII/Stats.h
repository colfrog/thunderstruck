#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Stats
{
public:
	Stats();
	~Stats();

	int get_score();
	int get_nb_ennemi_dead();

	void set_score(int score);
	int set_nb_ennemi_dead(int nb_ennemi_dead);

	void afficher();

private:
	int m_score;
	int m_nb_ennemi_dead;
};