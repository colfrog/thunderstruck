#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

#include "CharacterTable.h"
#include "GameLabel.h"
#include "GameButton.h"
#include "AttackButton.h"
#include "TowerLabel.h"
#include "LevelLabel.h"
class GameWidget : public QWidget
{
	Q_OBJECT
public:
	GameWidget(Jeu *j);
	~GameWidget();
	QPushButton *shopButton;
private:
	QVBoxLayout *VBox;
	QHBoxLayout *HBoxLabel;
	QHBoxLayout *HBoxButton;
	// TODO: Remplacer par CharacterTable lorsque finie
	//QTableWidget *Table;
	CharacterTable *Table;

	AttackButton *ButtonLeft;
	AttackButton *ButtonRight;
	AttackButton *ButtonTop;
	AttackButton *ButtonBot;
	GameButton *ButtonWait;

	GameLabel *labelLevel;
	GameLabel *labelTower;

	Jeu *jeu;
};

#endif // MAINWIDGET_H
