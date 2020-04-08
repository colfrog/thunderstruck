#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QObject>
#include <QWidget>
#include <Jeu.h>
#include "GameWidget/GameWidget.h"

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(Jeu *j, QWidget *parent = nullptr);
	~MainWindow();
private:
	Jeu *jeu;
	GameWidget *gameWidget;
};
#endif // MAINWINDOW_H
