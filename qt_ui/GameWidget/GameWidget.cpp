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
	/*
	QObject::connect(ButtonTop, SIGNAL(clicked()), ButtonTop, SLOT(gameUpdate()));
	QObject::connect(ButtonBot, SIGNAL(clicked()), ButtonBot, SLOT(gameUpdate()));
	QObject::connect(ButtonRight, SIGNAL(clicked()), ButtonRight, SLOT(gameUpdate()));
	QObject::connect(ButtonLeft, SIGNAL(clicked()), ButtonLeft, SLOT(gameUpdate()));

	QObject::connect(ButtonWait, SIGNAL(clicked()), ButtonWait, SLOT(gameUpdate())); */
	
	setLayout(VBox);
}

GameWidget::~GameWidget(){

}
