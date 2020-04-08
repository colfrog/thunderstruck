#include "GameLabel.h"


GameLabel::GameLabel(QString s) {
	setText(s);
}

GameLabel::~GameLabel() {

}

void GameLabel::update(QString s) {
	setText(s);
}

void GameLabel::updated() {

}