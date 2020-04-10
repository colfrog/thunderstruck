#include "GameWidget.h"

GameWidget::GameWidget(Jeu *j) :
	jeu(j)
{
	VBox = new QVBoxLayout;
	HBoxLabel = new QHBoxLayout;
	HBoxButton = new QHBoxLayout;

	// TODO: Remplacer par CharacterTable lorsque finie
	Table = new QTableWidget();

	ButtonLeft = new AttackButton(jeu, "left", Direction::LEFT);
	ButtonRight = new AttackButton(jeu, "Right", Direction::RIGHT);
	ButtonTop = new AttackButton(jeu, "Top", Direction::UP);
	ButtonBot = new AttackButton(jeu, "Bottom", Direction::DOWN);
	ButtonWait = new GameButton(jeu, "Attendre");

	labelLevel = new LevelLabel(jeu, "Niveau: ");
	labelTower = new TowerLabel(jeu, "HP: ");


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
