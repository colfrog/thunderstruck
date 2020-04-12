#include "MainWindow.h"

MainWindow::MainWindow(Jeu *j, QWidget *parent) :
	QMainWindow(parent),
	jeu(j),
	gameGraphics(jeu)
{
	setWindowTitle("TowerDefense");
	setWindowIcon(QIcon(":icon.png"));
	setCentralWidget(gameGraphics.widget());

	setMinimumSize(800, 800);
}

MainWindow::~MainWindow()
{
}
