#include "GameWidget.h"

GameWidget::GameWidget(Jeu *j) :
	jeu(j)
{
	VBox = new QVBoxLayout;
	HBoxLabel = new QHBoxLayout;
	HBoxButton = new QHBoxLayout;

	Table = new CharacterTable(jeu);

	ButtonLeft = new AttackButton(jeu, "Attaquer Ouest", Direction::LEFT);
	ButtonRight = new AttackButton(jeu, "Attaquer Est", Direction::RIGHT);
	ButtonTop = new AttackButton(jeu, "Attaquer Nord", Direction::UP);
	ButtonBot = new AttackButton(jeu, "Attaquer Sud", Direction::DOWN);
	ButtonWait = new GameButton(jeu, "Attendre");

	labelLevel = new LevelLabel(jeu, "Niveau: ");
	labelTower = new TowerLabel(jeu, "Vie de la Tour: ");


	HBoxLabel->addWidget(labelLevel->widget());
	HBoxLabel->addWidget(labelTower->widget(), 0, Qt::AlignRight);

	HBoxButton->addWidget(ButtonLeft->widget());
	HBoxButton->addWidget(ButtonBot->widget());
	HBoxButton->addWidget(ButtonTop->widget());
	HBoxButton->addWidget(ButtonRight->widget());

	VBox->addLayout(HBoxLabel);
	VBox->addWidget(Table->widget());
	VBox->addLayout(HBoxButton);
	VBox->addWidget(ButtonWait->widget());

	setLayout(VBox);

	gameAction = new GameAction(jeu);

	// Connection des boutons à gameAction
	QObject::connect(ButtonWait, SIGNAL(gameUpdated()), gameAction, SLOT(gameUpdate()));
	QObject::connect(ButtonLeft, SIGNAL(gameUpdated()), gameAction, SLOT(gameUpdate()));
	QObject::connect(ButtonRight, SIGNAL(gameUpdated()), gameAction, SLOT(gameUpdate()));
	QObject::connect(ButtonTop, SIGNAL(gameUpdated()), gameAction, SLOT(gameUpdate()));
	QObject::connect(ButtonBot, SIGNAL(gameUpdated()), gameAction, SLOT(gameUpdate()));

	// Connection de gameAction à chaque objet qui n'est pas un bouton
	QObject::connect(gameAction, SIGNAL(gameUpdated()), labelLevel, SLOT(gameUpdate()));
	QObject::connect(gameAction, SIGNAL(gameUpdated()), labelTower, SLOT(gameUpdate()));
	QObject::connect(gameAction, SIGNAL(gameUpdated()), Table, SLOT(gameUpdate()));
}

GameWidget::~GameWidget(){
	delete Table;
	delete ButtonLeft;
	delete ButtonRight;
	delete ButtonTop;
	delete ButtonBot;
	delete ButtonWait;
	delete labelLevel;
	delete labelTower;
	delete gameAction;
	delete jeu;
	delete HBoxLabel;
	delete HBoxButton;
	delete VBox;
}
