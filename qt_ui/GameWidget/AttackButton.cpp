#pragma once
#include "AttackButton.h"



AttackButton::AttackButton(Jeu* j, QString s, Direction d):GameButton(Jeu* j, QString s)
{
	dir = d;
}

void AttackButton::gameUpdate()
{
	cout<<(*j).attack(dir)<<endl;
}