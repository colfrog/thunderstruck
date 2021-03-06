#include "Lane.h"
#include "Jeu.h"

Lane::Lane(Jeu *jeu, Direction dir) :
	Element(jeu),
	m_dir(dir)
{
	m_position = m_jeu->tour().position() - get_end_position();
}

Lane::~Lane() {}

int Lane::damage(const Weapon &w, int mod) {
	if (m_enemies.empty())
		return 0;

	int damage = m_enemies.front()->damage(w, mod);
	if (m_enemies.front()->get_hp() == 0)
		remove_front_enemy();

	return damage;
}

int Lane::attack(Element &elem, int mod) {
	if (m_enemies.empty())
		return 0;

	int damage = m_enemies.front()->attack(elem);
	remove_front_enemy();
	return damage;
}

bool Lane::is_empty(const Coord &position) {
	for (const Enemy *e : m_enemies)
		if (position == e->position())
			return false;

	return true;
}

bool Lane::reached_end(const Enemy *e) {
	return e->position() == Coord(0, 0);
}

void Lane::remove_front_enemy() {
	// Commence par tuer l'ennemi
	m_enemies.front()->set_hp(0);
	// Ajouter Enemy::get_drop au joueur
	Player &p = m_jeu->tour().player();
	p.set_argent(p.get_argent() + m_enemies.front()->get_drop());

	m_jeu->enemy_killed(m_enemies.front());
	if (m_jeu->kill_count() % 10 == 0)
		m_jeu->niveau().prochain();

	// Ne pas libérer la mémoire, ils appartiennent à l'application
	m_enemies.pop_front();
	if (m_enemies.size() != 0)
		m_enemies.front()->set_next_enemy(nullptr);
}

bool Lane::can_spawn() {
	return is_empty(m_position);
}

void Lane::spawn() {
	Weapon w;
	w.set_attack(1);
	Defense d;
	Enemy *e = make_enemy("Zombie", 10, w, d);
	if (!m_enemies.empty())
		e->set_next_enemy(m_enemies.back());

	m_enemies.push_back(e);
}

void Lane::set_lane_id(int lane_id) {
	m_lane_id = lane_id;
}
void Lane::set_distance(int distance) {
	m_distance = distance;
}

Direction Lane::get_direction() const {
	return m_dir;
}
Coord Lane::get_end_position() const {
	// TODO: Rajouter à la distance si la tour est tombée
	return m_position + DirTools::vectors[DirTools::opposites[m_dir]]*m_distance;
}
int Lane::get_distance() const {
	return m_distance;
}
int Lane::get_lane_id() const {
	return m_lane_id;
}
int Lane::get_enemy_count() const {
	return (int) m_enemies.size();
}

Enemy *Lane::make_enemy(string name, int drop) {
	Enemy *enemy = new Enemy(m_jeu, this, name);
	enemy->set_position(m_position);
	enemy->set_direction(DirTools::opposites[m_dir]);
	enemy->set_drop(drop);
	return enemy;
}
Enemy *Lane::make_enemy(string name, int drop, Weapon weapon, Defense defense) {
	Enemy *enemy = make_enemy(name, drop);
	enemy->set_weapon(weapon);
	enemy->set_defense(defense);
	return enemy;
}

void Lane::step() {
	if (m_jeu->niveau().should_spawn() && can_spawn())
		spawn();

	if (m_enemies.size() == 0)
		return;

	for (Enemy *e : m_enemies)
		e->step();

	if (reached_end(m_enemies.front())) {
		attack(m_jeu->tour());
	}
}

void Lane::show() const {
	std::cout << "Lane " << DirTools::dir_names[m_dir] <<
		": position " << m_position.to_string() <<
		", end_position " << get_end_position().to_string() << std::endl;

	for (const Enemy *e : m_enemies)
		e->show();
}
