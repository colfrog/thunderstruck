#include "Personnage.h"

Personnage::Personnage() : Element() {
	name = "";
	hp = 100;
	defense = Defense();
	weapon = Weapon();
}
Personnage::Personnage(string n) : Element() {
	name = n;
	hp = 100;
	defense = Defense();
	weapon = Weapon();
}
Personnage::~Personnage() {

}

string Personnage::getName() {
	return name;
}
void Personnage::setName(string n) {
	name = n;
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
