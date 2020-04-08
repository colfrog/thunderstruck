#include "gamewidget.h"

GameWidget::GameWidget()
{

    VBox = new QVBoxLayout;
    HBoxLabel = new QHBoxLayout;
    HBoxButton = new QHBoxLayout;

    Table = new GameTableWidget;

    ButtonLeft = new GameBouton("left");
    ButtonRight = new GameBouton("Right");
    ButtonTop = new GameBouton("Top");
    ButtonBot = new GameBouton("Bottom");
    ButtonWait = new GameBouton("Attendre");

    labelLife = new GameLabel("Life:100");
    labelTower = new GameLabel("Tower:100");

    HBoxLabel->addWidget(labelLife);
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
