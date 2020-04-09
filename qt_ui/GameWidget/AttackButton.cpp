#pragma once
#include "AttackButton.h"



AttackButton::AttackButton(Jeu* j, QString s, Direction d) : GameButton(j, s)
{
	dir = d;
} 

void AttackButton::gameUpdate()
{
	cout<<jeu->attack(dir)<<endl;
}
