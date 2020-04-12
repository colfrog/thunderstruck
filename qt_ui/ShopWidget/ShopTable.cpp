#include "ShopTable.h"

ShopTable::ShopTable(Jeu *jeu) {
	m_jeu = jeu;

	m_table_potion = new QTableWidget(0,5);
	list<QString> informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Vie recuperee"};

	int index = 0;
	for (QString info : informations) {
		m_table_potion->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Potion p : m_jeu->tour().player().get_shop()->get_list_potion()) {
		m_table_potion->setRowCount(m_table_potion->rowCount() + 1);

		m_table_potion->setItem(index, 0, new QTableWidgetItem(QString::number(p.get_id())));
		m_table_potion->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(p.get_name())));
		m_table_potion->setItem(index, 2, new QTableWidgetItem(QString::number(p.get_price_buy())));
		m_table_potion->setItem(index, 3, new QTableWidgetItem(QString::number(p.get_price_sell())));
		m_table_potion->setItem(index, 4, new QTableWidgetItem(QString::number(p.get_hp_restore())));
		index++;
	}


	m_table_weapon = new QTableWidget(0, 5);
	informations.clear();
	informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Attaque" };

	index = 0;
	for (QString info : informations) {
		m_table_weapon->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Weapon w : m_jeu->tour().player().get_shop()->get_list_weapon()) {
		m_table_weapon->setRowCount(m_table_weapon->rowCount() + 1);

		m_table_weapon->setItem(index, 0, new QTableWidgetItem(QString::number(w.get_id())));
		m_table_weapon->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(w.get_name())));
		m_table_weapon->setItem(index, 2, new QTableWidgetItem(QString::number(w.get_price_buy())));
		m_table_weapon->setItem(index, 3, new QTableWidgetItem(QString::number(w.get_price_sell())));
		m_table_weapon->setItem(index, 4, new QTableWidgetItem(QString::number(w.get_attack())));
		index++;
	}


	m_table_defense = new QTableWidget(0, 5);
	informations.clear();
	informations = { "Id","Nom","Prix d'achat", "Prix de vente", "Armure" };

	index = 0;
	for (QString info : informations) {
		m_table_defense->setHorizontalHeaderItem(index, new QTableWidgetItem(info));
		index++;
	}

	index = 0;
	for (Defense d : m_jeu->tour().player().get_shop()->get_list_defense()) {
		m_table_defense->setRowCount(m_table_defense->rowCount() + 1);

		m_table_defense->setItem(index, 0, new QTableWidgetItem(QString::number(d.get_id())));
		m_table_defense->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(d.get_name())));
		m_table_defense->setItem(index, 2, new QTableWidgetItem(QString::number(d.get_price_buy())));
		m_table_defense->setItem(index, 3, new QTableWidgetItem(QString::number(d.get_price_sell())));
		m_table_defense->setItem(index, 4, new QTableWidgetItem(QString::number(d.get_armure())));
		index++;
	}
	
}
ShopTable::~ShopTable() {
	delete m_table_potion;
	delete m_table_weapon;
	delete m_table_defense;
	delete m_jeu;
}

QTableWidget *ShopTable::widgetPotion() {
	return m_table_potion;
}
QTableWidget *ShopTable::widgetWeapon() {
	return m_table_weapon;
}
QTableWidget *ShopTable::widgetDefense() {
	return m_table_defense;
}

void ShopTable::shopUpdateBuy(int id) {
	int category = m_jeu->tour().player().get_shop()->find_category(id);
	int argent = m_jeu->tour().player().get_argent();

	if (category == 1) {//Achat d'une potion
		Potion potion = m_jeu->tour().player().get_shop()->buy_potion(id);

		if (potion.get_id() == -1) { //Vérifie si l'id de l'item existe
			emit not_id();
		}
		else {
			if (argent >= potion.get_price_buy()) {//Vérifie si le joueu a assez d'argent
				m_jeu->tour().player().set_argent(argent - potion.get_price_buy());
				m_jeu->tour().player().set_hp(m_jeu->tour().player().get_hp() + potion.get_hp_restore());

				for (int index = 0; index < m_table_potion->rowCount(); index++) {//Enleve l'item du QTableWidget
					if (potion.get_id() == m_table_potion->item(index, 0)->text().toInt()) {
						m_table_potion->removeRow(index);
					}
				}

				emit bought(potion.get_name());
			}
			else {
				
				m_jeu->tour().player().get_shop()->sell_potion(potion); //retourne la potion au shop
				emit not_enough_money();
			}
		}
	}
	else if (category == 2) {//Achat d'une arme
		Weapon weapon = m_jeu->tour().player().get_shop()->buy_weapon(id);

		if (weapon.get_id() == -1) { //Vérifie si l'id de l'item existe
			emit not_id();
		}
		else {
			if (argent >= weapon.get_price_buy()) {//Vérifie si le joueu a assez d'argent
				m_jeu->tour().player().set_argent(argent - weapon.get_price_buy());
				m_jeu->tour().player().set_weapon(weapon);

				for (int index = 0; index < m_table_weapon->rowCount(); index++) {//Enleve l'item du QTableWidget
					if (weapon.get_id() == m_table_weapon->item(index, 0)->text().toInt()) {
						m_table_weapon->removeRow(index);
					}
				}

				emit bought(weapon.get_name());
			}
			else {
				m_jeu->tour().player().get_shop()->sell_weapon(weapon); //retourne l'arme au shop
				emit not_enough_money();
			}
		}
	}
	else if (category == 3) {//Achat d'une armure
		Defense defense = m_jeu->tour().player().get_shop()->buy_defense(id);

		if (defense.get_id() == -1) { //Vérifie si l'id de l'item existe
			emit not_id();
		}
		else {
			if (argent >= defense.get_price_buy()) {//Vérifie si le joueu a assez d'argent
				m_jeu->tour().player().set_argent(argent - defense.get_price_buy());
				m_jeu->tour().player().set_defense(defense);

				for (int index = 0; index < m_table_defense->rowCount(); index++) {//Enleve l'item du QTableWidget
					if (defense.get_id() == m_table_defense->item(index, 0)->text().toInt()) {
						m_table_defense->removeRow(index);
					}
				}

				emit bought(defense.get_name());
			}
			else {
				m_jeu->tour().player().get_shop()->sell_defense(defense); //retourne l'arme au shop
				emit not_enough_money();
			}
		}
	} else {//L'id de l'item n'existe pas
		emit not_id();
	}
}

void ShopTable::shopUpdateSell(int id) {
	int category = m_jeu->tour().player().get_shop()->find_category(id);
	int argent = m_jeu->tour().player().get_argent();
	Weapon weaponVide, weaponPlayer = m_jeu->tour().player().get_weapon();
	Defense defenseVide, defensePlayer = m_jeu->tour().player().get_defense();

	switch (category) {
	case 2://Vente de l'arme du joueur		
		m_table_weapon->setRowCount(m_table_weapon->rowCount() + 1);

		m_table_weapon->setItem(m_table_weapon->rowCount() - 1, 0, new QTableWidgetItem(QString::number(weaponPlayer.get_id())));
		m_table_weapon->setItem(m_table_weapon->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(weaponPlayer.get_name())));
		m_table_weapon->setItem(m_table_weapon->rowCount() - 1, 2, new QTableWidgetItem(QString::number(weaponPlayer.get_price_buy())));
		m_table_weapon->setItem(m_table_weapon->rowCount() - 1, 3, new QTableWidgetItem(QString::number(weaponPlayer.get_price_sell())));
		m_table_weapon->setItem(m_table_weapon->rowCount() - 1, 4, new QTableWidgetItem(QString::number(weaponPlayer.get_attack())));

		m_table_weapon->sortItems(2, Qt::AscendingOrder);

		m_jeu->tour().player().get_shop()->sell_weapon(weaponPlayer);
		m_jeu->tour().player().set_argent(argent + weaponPlayer.get_price_sell());
		m_jeu->tour().player().set_weapon(weaponVide);


		break;
	case 3://Vente de l'armure du joueur
		m_table_defense->setRowCount(m_table_defense->rowCount() + 1);

		m_table_defense->setItem(m_table_defense->rowCount() - 1, 0, new QTableWidgetItem(QString::number(defensePlayer.get_id())));
		m_table_defense->setItem(m_table_defense->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(defensePlayer.get_name())));
		m_table_defense->setItem(m_table_defense->rowCount() - 1, 2, new QTableWidgetItem(QString::number(defensePlayer.get_price_buy())));
		m_table_defense->setItem(m_table_defense->rowCount() - 1, 3, new QTableWidgetItem(QString::number(defensePlayer.get_price_sell())));
		m_table_defense->setItem(m_table_defense->rowCount() - 1, 4, new QTableWidgetItem(QString::number(defensePlayer.get_armure())));

		m_table_defense->sortItems(2, Qt::AscendingOrder);

		m_jeu->tour().player().get_shop()->sell_defense(defensePlayer);
		m_jeu->tour().player().set_argent(argent + defensePlayer.get_price_sell());
		m_jeu->tour().player().set_defense(defenseVide);

		break;
	case -1://L'id de l'item n'existe pas
		emit no_item();
		break;
	}
}