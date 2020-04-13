TEMPLATE = app
QT += widgets

INCLUDEPATH += libWWIII

HEADERS += \
	libWWIII/Direction.h \
	libWWIII/Elements/Enemy.h \
	libWWIII/Elements/Element.h \
	libWWIII/Elements/Personnage.h \
	libWWIII/Elements/Tour.h \
	libWWIII/Elements/Lane.h \
	libWWIII/Elements/Player.h \
	libWWIII/Items/Item.h \
	libWWIII/Items/Potion.h \
	libWWIII/Items/Weapon.h \
	libWWIII/Items/Defense.h \
	libWWIII/Shop.h \
	libWWIII/Stats.h \
	libWWIII/Niveau.h \
	libWWIII/Coord.h \
	libWWIII/Jeu.h \
	qt_ui/GameWidget/AttackButton.h \
	qt_ui/GameWidget/GameAction.h \
	qt_ui/GameWidget/GameButton.h \
	qt_ui/GameWidget/GameObject.h \
	qt_ui/GameWidget/GameLabel.h \
	qt_ui/GameWidget/LevelLabel.h \
	qt_ui/GameWidget/TowerLabel.h \
	qt_ui/GameWidget/CharacterTable.h \
	qt_ui/GameWidget/GameWidget.h \
	qt_ui/MainWindow.h

SOURCES += \
	libWWIII/Elements/Element.cpp \
	libWWIII/Elements/Enemy.cpp \
	libWWIII/Elements/Tour.cpp \
	libWWIII/Elements/Lane.cpp \
	libWWIII/Elements/Personnage.cpp \
	libWWIII/Elements/Player.cpp \
	libWWIII/Items/Item.cpp \
	libWWIII/Items/Potion.cpp \
	libWWIII/Items/Weapon.cpp \
	libWWIII/Items/Defense.cpp \
	libWWIII/Stats.cpp \
	libWWIII/Shop.cpp \
	libWWIII/Niveau.cpp \
	libWWIII/Coord.cpp \
	libWWIII/Jeu.cpp \
	qt_ui/GameWidget/CharacterTable.cpp \
	qt_ui/GameWidget/GameWidget.cpp \
	qt_ui/MainWindow.cpp \
	qt_ui/main.cpp

CONFIG += c++17
