#include "MainWindow.h"

MainWindow::MainWindow(Jeu *j, QWidget *parent)
	: QMainWindow(parent),
	jeu(j)
{
	gameWidget = new GameWidget(jeu);

	setWindowTitle("TowerDefense");
	setWindowIcon(QIcon(":icon.ico"));
	setCentralWidget(gameWidget);

	setMinimumSize(800, 600);
}

MainWindow::~MainWindow()
{
}
