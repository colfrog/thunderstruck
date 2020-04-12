#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

#include "CharacterTable.h"
#include "GameAction.h"
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
private:
	QVBoxLayout *VBox;
	QHBoxLayout *HBoxLabel;
	QHBoxLayout *HBoxButton;
	CharacterTable *Table;

	AttackButton *ButtonLeft;
	AttackButton *ButtonRight;
	AttackButton *ButtonTop;
	AttackButton *ButtonBot;
	GameButton *ButtonWait;

	GameLabel *labelLevel;
	GameLabel *labelTower;

	GameAction *gameAction;
	Jeu *jeu;
};

#endif // MAINWIDGET_H
