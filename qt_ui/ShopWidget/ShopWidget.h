#ifndef SHOPWIDGET_H
#define SHOPWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

#include "Jeu.h"
#include "ShopTable.h"

class ShopWidget : public QWidget
{
	Q_OBJECT
public:
	ShopWidget(Jeu *j);
	~ShopWidget();
public slots:
	void getId();
	void updateMoneyLabel();
signals:
	void idBuy(int id);
	void idSell(int id);
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
};
#endif // SHOPWIDGET_H
