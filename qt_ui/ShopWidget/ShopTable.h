#pragma once

#include <QTableWidget>
#include <QObject>
#include <Jeu.h>

class ShopTable : public QObject{
	Q_OBJECT
public:
	ShopTable(Jeu *jeu);
	~ShopTable();

	QTableWidget *widgetPotion();
	QTableWidget *widgetWeapon();
	QTableWidget *widgetDefense();

public slots:
	void shopUpdateBuy(int);
	void shopUpdateSell(int);

signals:
	void bought(string s);
	void selled(string s);
	void not_id();
	void not_enough_money();
	void no_item();

protected:
	QTableWidget *m_table_potion;
	QTableWidget *m_table_weapon;
	QTableWidget *m_table_defense;

	Jeu *m_jeu;
};