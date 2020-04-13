#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>
#include <QWidget>
#include <Jeu.h>

#include "GameWidget/GameWidget.h"
#include "ShopWidget/ShopWidget.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(Jeu *j, QWidget *parent = nullptr);
	~MainWindow();
public slots:
	void openShop();
private:
	Jeu *jeu;
	GameWidget *gameWidget;
	ShopWidget *shopWidget;

	QPushButton *shopButton;
};
#endif // MAINWINDOW_H
