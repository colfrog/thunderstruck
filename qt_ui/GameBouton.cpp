#include "GameBouton.h"

GameBouton::GameBouton(QString s) {
	setText(s);
}

GameBouton::~GameBouton() {

}

void GameBouton::updated()
{

}
void GameBouton::update(QString s)
{
	setText(s);
}