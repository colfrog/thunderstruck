#pragma once

#include <QTableWidget>
#include <QObject>
#include <Jeu.h>

class ShopTable : public QObject{
	Q_OBJECT
public:
	ShopTable(Jeu *jeu);
	~ShopTable();

	QWidget *widgetPotion();
	QWidget *widgetWeapon();
	QWidget *widgetDefense();
public slots:
	void shopUpdateBuy(int id);
	void shopUpdateSell(int id);
signals:
	void bought(string s);
	void selled(string s);
	void not_id();
	void not_enough_money();

protected:
	QTableWidget *m_table_potion;
	QTableWidget *m_table_weapon;
	QTableWidget *m_table_defense;

	Jeu *m_jeu;
};