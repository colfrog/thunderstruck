#ifndef SHOPWIDGET_H
#define SHOPWIDGET_H

#include <iostream>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

#include "Jeu.h"
#include "ShopTable.h"
#include "../GameWidget/GameWidget.h"

using namespace std;

class ShopWidget : public QWidget
{
	Q_OBJECT
public:
	ShopWidget(Jeu *j, GameWidget *gameWidget);
	~ShopWidget();
public slots:
	void getIdBuy();
	void getIdSell();

	void boughtItem(string);
	void selledItem(string);
	void invalidId();
	void needMoreMoney();
	void playerNoItem();

	void updateMoneyLabel();
signals:
	void idBuy(int id);
	void idSell(int id);

	void updateLabels();
private:
	QGridLayout *gridLayout;

	QLabel *shopLabel;
	QLabel *potionsLabel;
	QLabel *weaponsLabel;
	QLabel *armorsLabel;
	QLabel *enterIDLabel;
	QLabel *playerMoneyLabel;

	QTableWidget *potionsTable;
	QTableWidget *weaponsTable;
	QTableWidget *armorsTable;

	QLineEdit *itemIDTextEdit;

	QPushButton *buyButton;
	QPushButton *sellButton;

	Jeu *jeu;
	ShopTable *shopTable;
	GameWidget *gameWidget;
};
#endif // SHOPWIDGET_H
