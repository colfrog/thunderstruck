#include "MainWindow.h"

MainWindow::MainWindow(Jeu *j, QWidget *parent)
	: QMainWindow(parent),
	jeu(j)
{
	gameWidget = new GameWidget(jeu);

	setWindowTitle("TowerDefense");
	setCentralWidget(gameWidget);

	setMinimumSize(500, 500);
	setFixedSize(700, 800);
}

MainWindow::~MainWindow()
{
}
