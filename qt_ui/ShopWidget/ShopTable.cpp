#include "ShopTable.h"

ShopTable::ShopTable(Jeu jeu*) {
	m_table_potion = new QTableWidget(1,5);
	list<QString> informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Vie recuperee"};

	int index = 0;
	for (QString info : informations) {
		m_table->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Potion p : jeu.tour().player().get_shop().get_list_potion()) {
		m_table->setItem(index, 0, new QTableWidgetItem(QString::number(p.get_id())));
		m_table->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(p.get_name())));
		m_table->setItem(index, 2, new QTableWidgetItem(QString::number(p.get_price_buy())));
		m_table->setItem(index, 3, new QTableWidgetItem(QString::number(p.get_price_sell())));
		m_table->setItem(index, 4, new QTableWidgetItem(QString::number(p.get_hp_restore())));
		index++;
	}


	m_table_weapon = new QTableWidget(1, 5);
	informations.clear();
	informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Attaque" };

	index = 0;
	for (QString info : informations) {
		m_table->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Weapon w : jeu.tour().player().get_shop().get_list_weapon()) {
		m_table->setItem(index, 0, new QTableWidgetItem(QString::number(w.get_id())));
		m_table->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(w.get_name())));
		m_table->setItem(index, 2, new QTableWidgetItem(QString::number(w.get_price_buy())));
		m_table->setItem(index, 3, new QTableWidgetItem(QString::number(w.get_price_sell())));
		m_table->setItem(index, 4, new QTableWidgetItem(QString::number(w.get_attack())));
		index++;
	}


	m_table_defense = new QTableWidget(1, 5);
	informations.clear();
	informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Armure" };

	index = 0;
	for (QString info : informations) {
		m_table->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Defense d : jeu.tour().player().get_shop().get_list_defense()) {
		m_table->setItem(index, 0, new QTableWidgetItem(QString::number(d.get_id())));
		m_table->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(d.get_name())));
		m_table->setItem(index, 2, new QTableWidgetItem(QString::number(d.get_price_buy())));
		m_table->setItem(index, 3, new QTableWidgetItem(QString::number(d.get_price_sell())));
		m_table->setItem(index, 4, new QTableWidgetItem(QString::number(d.get_armure())));
		index++;
	}
}
ShopTable::~ShopTable() {
	delete m_table_potion;
	delete m_table_weapon;
	delete m_table_defense;
}

void ShopTable::shopUpdate() {

}