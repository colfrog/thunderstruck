#include "Tour.h"

Tour::Tour() : Element()
{
	set_position(0, 0);
}
Tour::~Tour()
{

}

Player Tour::get_player() {
	return m_player;
}

void Tour::set_player(Player player) {
	m_player = player;
}

void Tour::step() {
	m_player.step();
}