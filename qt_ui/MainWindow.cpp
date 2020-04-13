#include "MainWindow.h"

MainWindow::MainWindow(Jeu *j, QWidget *parent)
	: QMainWindow(parent),
	jeu(j)
{
	gameWidget = new GameWidget(jeu);

	setWindowTitle("TowerDefense");
	setWindowIcon(QIcon(":icon.png"));
	setCentralWidget(gameWidget);

	setMinimumSize(500, 500);
	setFixedSize(700, 800);

	shopButton = gameWidget->shopButton;
	connect(shopButton, SIGNAL(clicked()), this, SLOT(openShop()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::openShop() {
	shopWidget = new ShopWidget(jeu);
	
	shopWidget->setWindowTitle("Shop");
	shopWidget->setWindowIcon(QIcon(":icon.png"));

	shopWidget->setMinimumSize(500, 500);
	shopWidget->setFixedSize(500, 800);

	shopWidget->show();
}
