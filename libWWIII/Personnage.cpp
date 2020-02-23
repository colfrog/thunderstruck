#include "Personnage.h"

Personnage::Personnage() {
	hp = 100;
	defense = Defense();
	weapon = Weapon();
}
Personnage::~Personnage() {

}
unsigned long Personnage::getHp() {
	return hp;
}
void Personnage::setHP(unsigned long HP) {
	hp = HP;
}

Defense Personnage::getDefense() {
	return defense;
}
void Personnage::setDefense(Defense def) {
	defense = def;
}

Weapon Personnage::getWeapon() {
	return weapon;
}
void Personnage::setWeapon(Weapon w) {
	weapon = w;
}
