#pragma once

#include <QTableWidget>
#include <Jeu.h>

class ShopTable {
	Q_OBJECT
public:
	ShopTable(Jeu jeu*);
	~ShopTable();
public slots:
	void shopUpdate();
protected:
	QTableWidget *m_table_potion;
	QTableWidget *m_table_weapon;
	QTableWidget *m_table_defense;
};