#pragma once
#include "AttackButton.h"



AttackButton::AttackButton(Jeu* j, QString s, Direction dir):GameButton(Jeu* j, QString s)
{
	(*this).dir = dir;
}
void AttackButton::gameUpdated()
{
	(*j).attack(dir);
}