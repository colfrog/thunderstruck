#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "gametablewidget.h"
#include "gamelabel.h"
#include "GameBouton.h"
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    GameWidget();
    ~GameWidget();
private:
    QVBoxLayout *VBox;
    QHBoxLayout *HBoxLabel;
    QHBoxLayout *HBoxButton;
    GameTableWidget *Table;

    GameBouton *ButtonLeft;
    GameBouton *ButtonRight;
    GameBouton *ButtonTop;
    GameBouton *ButtonBot;
    GameBouton *ButtonWait;

    GameLabel *labelLife;
    GameLabel *labelTower;

};

#endif // MAINWIDGET_H
