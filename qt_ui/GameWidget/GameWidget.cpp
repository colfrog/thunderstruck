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
	shopButton = new QPushButton("Shop");

	labelLevel = new LevelLabel(jeu, "Niveau: ");
	labelTower = new TowerLabel(jeu, "Vie de la Tour: ");

	ShortCutTop = new QShortcut(Qt::Key_W, this);
	ShortCutLeft = new QShortcut(Qt::Key_A, this);
	ShortCutRight = new QShortcut(Qt::Key_D, this);
	ShortCutBot = new QShortcut(Qt::Key_S, this);
	ShortCutWait = new QShortcut(Qt::Key_Space, this);
	//To add when the button for the shop will be implemented
	//ShortCutShop = new QShortcut(Qt::Key_M, this);


	HBoxLabel->addWidget(labelLevel->widget());
	HBoxLabel->addWidget(labelTower->widget(), 0, Qt::AlignRight);

	HBoxButton->addWidget(ButtonLeft->widget());
	HBoxButton->addWidget(ButtonRight->widget());
	

	VBox->addLayout(HBoxLabel);
	VBox->addWidget(Table->widget());
	VBox->addWidget(ButtonTop->widget());
	VBox->addLayout(HBoxButton);
	VBox->addWidget(ButtonBot->widget());
	VBox->addWidget(ButtonWait->widget());
	VBox->addWidget(shopButton);

	setLayout(VBox);

	gameAction = new GameAction(jeu);

	// Connection des shortcut à gameAction
	QObject::connect(ShortCutWait, SIGNAL(activated()), ButtonWait, SLOT(shortCutActivated()));
	QObject::connect(ShortCutLeft, SIGNAL(activated()), ButtonLeft, SLOT(shortCutActivated()));
	QObject::connect(ShortCutRight, SIGNAL(activated()), ButtonRight, SLOT(shortCutActivated()));
	QObject::connect(ShortCutTop, SIGNAL(activated()), ButtonTop, SLOT(shortCutActivated()));
	QObject::connect(ShortCutBot, SIGNAL(activated()), ButtonBot, SLOT(shortCutActivated()));/**/
	//QObject::connect(ShortCutShop, SIGNAL(activated()), ButtonBot, SLOT(shortCutActivated()));

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
	delete ShortCutBot;
	delete ShortCutLeft;
	delete ShortCutRight;
	//delete ShortCutShop;
	delete ShortCutTop;
	delete ShortCutWait;
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

void GameWidget::updateTable()
{
	Table->gameUpdate();
}

