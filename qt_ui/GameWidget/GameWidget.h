#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>

#include "GameLabel.h"
#include "GameButton.h"
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
	// TODO: Remplacer par CharacterTable lorsque finie
	QTableWidget *Table;

	GameButton *ButtonLeft;
	GameButton *ButtonRight;
	GameButton *ButtonTop;
	GameButton *ButtonBot;
	GameButton *ButtonWait;

//	LevelLabel *labelLevel;
//	TowerLabel *labelTower;
	QLabel *labelLevel;
	QLabel *labelTower;

	Jeu *jeu;
};

#endif // MAINWIDGET_H
