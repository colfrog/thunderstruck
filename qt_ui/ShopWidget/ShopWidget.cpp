#include "ShopWidget.h"

ShopWidget::ShopWidget(Jeu *j) :
	jeu(j)
{
	ShopTable *shopTable = new ShopTable(jeu);
	gridLayout = new QGridLayout;

	shopLabel = new QLabel("Magasin");
	potionsLabel = new QLabel("Potions");
	weaponsLabel = new QLabel("Armes");
	armorsLabel = new QLabel("Armures");
	enterIDLabel = new QLabel("Entrer l'ID de l'item");
	playerMoneyLabel = new QLabel("Argent: 100");

	potionsBrowser = shopTable->widgetPotion();
	weaponsBrowser = shopTable->widgetWeapon();
	armorsBrowser = shopTable->widgetDefense();

	itemIDTextEdit = new QTextEdit();

	buyButton = new QPushButton("Acheter");
	sellButton = new QPushButton("Vendre");

	gridLayout->addWidget(shopLabel, 0, 0, 1, 2, Qt::AlignCenter);
	gridLayout->addWidget(potionsLabel, 1, 0, Qt::AlignLeft);
	gridLayout->addWidget(potionsBrowser, 2, 0, 1, 2);
	gridLayout->addWidget(weaponsLabel, 3, 0, 1, 2, Qt::AlignLeft);
	gridLayout->addWidget(weaponsBrowser, 4, 0, 1, 2);
	gridLayout->addWidget(armorsLabel, 5, 0, 1, 2, Qt::AlignLeft);
	gridLayout->addWidget(armorsBrowser, 6, 0, 1, 2);
	gridLayout->addWidget(enterIDLabel, 7, 0, 1, 2, Qt::AlignCenter);
	gridLayout->addWidget(itemIDTextEdit, 8, 0, 1, 2);
	gridLayout->addWidget(buyButton, 9, 0,1,1);
	gridLayout->addWidget(sellButton, 9, 1,1,1);
	gridLayout->addWidget(playerMoneyLabel, 10, 0,1,2, Qt::AlignCenter);



	setLayout(gridLayout);

}

ShopWidget::~ShopWidget() {

}


