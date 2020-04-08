#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    

    gameWidget = new GameWidget;
    setCentralWidget(gameWidget);
    setWindowTitle("TowerDefense");
}

MainWindow::~MainWindow()
{

}

