#include "MainWindow.h"

MainWindow::MainWindow(Jeu *j, QWidget *parent)
	: QMainWindow(parent),
	jeu(j)
{
	gameWidget = new GameWidget(jeu);
	ShortCutShop = new QShortcut(Qt::Key_M, this);

	setWindowTitle("TowerDefense");
	setWindowIcon(QIcon(":icon.ico"));
	setCentralWidget(gameWidget);

	setMinimumSize(800, 600);
	shopButton = gameWidget->shopButton;
	connect(shopButton, SIGNAL(clicked()), this, SLOT(openShop()));
	connect(ShortCutShop, SIGNAL(activated()), this, SLOT(openShop()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::openShop() {
	shopWidget = new ShopWidget(jeu, gameWidget);
	
	shopWidget->setWindowTitle("Shop");
	shopWidget->setWindowIcon(QIcon(":icon.png"));

	shopWidget->setMinimumSize(600, 500);

	shopWidget->show();
}
