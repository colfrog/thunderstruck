#include "GameWidget.h"

GameWidget::GameWidget(Jeu *j) :
	jeu(j)
{
	VBox = new QVBoxLayout;
	HBoxLabel = new QHBoxLayout;
	HBoxButton = new QHBoxLayout;

	// TODO: Remplacer par CharacterTable lorsque finie
	Table = new QTableWidget();

	ButtonLeft = new GameButton(jeu, "left");
	ButtonRight = new GameButton(jeu, "Right");
	ButtonTop = new GameButton(jeu, "Top");
	ButtonBot = new GameButton(jeu, "Bottom");
	ButtonWait = new GameButton(jeu, "Attendre");

	// labelLevel = new LevelLabel(jeu);
	// labelTower = new towerLabel(jeu);
	labelLevel = new GameLabel(jeu, "niveau");
	labelTower = new GameLabel(jeu, "tour");

	HBoxLabel->addWidget(labelLevel->widget());
	HBoxLabel->addWidget(labelTower->widget(), 0, Qt::AlignRight);

	HBoxButton->addWidget(ButtonLeft->widget());
	HBoxButton->addWidget(ButtonTop->widget());
	HBoxButton->addWidget(ButtonBot->widget());
	HBoxButton->addWidget(ButtonRight->widget());

	VBox->addLayout(HBoxLabel);
	VBox->addWidget(Table);
	VBox->addLayout(HBoxButton);
	VBox->addWidget(ButtonWait->widget());

	setLayout(VBox);
}

GameWidget::~GameWidget(){

}
