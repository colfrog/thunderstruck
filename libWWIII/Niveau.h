#include <random>

class Niveau {
public:
	Niveau(double dp, double mp);
	~Niveau() {}

	bool should_drop();
	bool should_move();

	const double drop_prob;
	const double move_prob;

	double drop_bonus() const;
	double move_bonus() const;

	void set_drop_bonus(double bonus);
	void set_move_bonus(double bonus);

private:
	bool decide(double prob);

	double m_drop_bonus = 0;
	double m_move_bonus = 0;

	std::default_random_engine m_randgen;
	std::uniform_int_distribution<int> m_unidist;
};
