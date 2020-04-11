#include "ShopWidget.h"

ShopWidget::ShopWidget(Jeu *j) :
	jeu(j)
{
	shopTable = new ShopTable(j);
	gridLayout = new QGridLayout();

	shopLabel = new QLabel("Magasin");
	potionsLabel = new QLabel("Potions");
	weaponsLabel = new QLabel("Armes");
	armorsLabel = new QLabel("Armures");
	enterIDLabel = new QLabel("Entrer l'ID de l'item");
	playerMoneyLabel = new QLabel();
	playerMoneyLabel->setText(QString::fromStdString("Argent : ") + QString::number(j->tour().player().get_argent()));

	potionsTable = shopTable->widgetPotion();
	weaponsTable = shopTable->widgetWeapon();
	armorsTable = shopTable->widgetDefense();

	itemIDTextEdit = new QLineEdit();

	buyButton = new QPushButton("Acheter");
	sellButton = new QPushButton("Vendre");

	itemIDTextEdit->setValidator(new QIntValidator(0, 999, this));

	gridLayout->addWidget(shopLabel, 0, 0, 1, 2, Qt::AlignCenter);
	gridLayout->addWidget(potionsLabel, 1, 0, Qt::AlignLeft);
	gridLayout->addWidget(potionsTable, 2, 0, 1, 2);
	gridLayout->addWidget(weaponsLabel, 3, 0, 1, 2, Qt::AlignLeft);
	gridLayout->addWidget(weaponsTable, 4, 0, 1, 2);
	gridLayout->addWidget(armorsLabel, 5, 0, 1, 2, Qt::AlignLeft);
	gridLayout->addWidget(armorsTable, 6, 0, 1, 2);
	gridLayout->addWidget(enterIDLabel, 7, 0, 1, 2, Qt::AlignCenter);
	gridLayout->addWidget(itemIDTextEdit, 8, 0, 1, 2);
	gridLayout->addWidget(buyButton, 9, 0,1,1);
	gridLayout->addWidget(sellButton, 9, 1,1,1);
	gridLayout->addWidget(playerMoneyLabel, 10, 0,1,2, Qt::AlignCenter);

	QObject::connect(buyButton, SIGNAL(clicked()), this, SLOT(getId()));
	QObject::connect(this, SIGNAL(id(int)), shopTable, SLOT(updateShopBuy(int)));

	QObject::connect(sellButton, SIGNAL(clicked()), this, SLOT(updateMoneyLabel()));

	setLayout(gridLayout);
}

ShopWidget::~ShopWidget() {

}

void ShopWidget::getId() {
	emit idBuy(itemIDTextEdit->text().toInt());
}

void ShopWidget::updateMoneyLabel() {
	playerMoneyLabel->setText(QString::fromStdString("Argent : ") + QString::number(jeu->tour().player().get_argent()));
	
}