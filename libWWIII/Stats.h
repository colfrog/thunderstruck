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
	int get_kills();

	void set_score(int score);
	void set_kills(int kills);

	void afficher();

private:
	int m_score;
	int m_kills;
};
