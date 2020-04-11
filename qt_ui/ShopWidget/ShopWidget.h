#ifndef SHOPWIDGET_H
#define SHOPWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QTextBrowser>


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

	QTextEdit *itemIDTextEdit;

	QPushButton *buyButton;
	QPushButton *sellButton;

	Jeu *jeu;
};
#endif // SHOPWIDGET_H
