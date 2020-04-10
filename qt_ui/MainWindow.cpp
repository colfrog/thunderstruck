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
}

MainWindow::~MainWindow()
{
}
