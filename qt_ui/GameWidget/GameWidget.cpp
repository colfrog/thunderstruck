#include "GameWidget.h"

GameWidget::GameWidget(Jeu *j) :
	jeu(j)
{
	VBox = new QVBoxLayout;
	HBoxLabel = new QHBoxLayout;
	HBoxButton = new QHBoxLayout;

	Table = new CharacterTable(j);

	ButtonLeft = new GameButton(jeu, "left");
	ButtonRight = new GameButton(jeu, "Right");
	ButtonTop = new GameButton(jeu, "Top");
	ButtonBot = new GameButton(jeu, "Bottom");
	ButtonWait = new GameButton(jeu, "Attendre");

	// labelLevel = new LevelLabel(jeu);
	// labelTower = new towerLabel(jeu);
	labelLevel = new QLabel("niveau");
	labelTower = new QLabel("tour");

	HBoxLabel->addWidget(labelLevel);
	HBoxLabel->addWidget(labelTower, 0, Qt::AlignRight);

	HBoxButton->addWidget(ButtonLeft);
	HBoxButton->addWidget(ButtonTop);
	HBoxButton->addWidget(ButtonBot);
	HBoxButton->addWidget(ButtonRight);

	VBox->addLayout(HBoxLabel);
	VBox->addWidget(Table);
	VBox->addLayout(HBoxButton);
	VBox->addWidget(ButtonWait);

	setLayout(VBox);
}

GameWidget::~GameWidget(){

}
