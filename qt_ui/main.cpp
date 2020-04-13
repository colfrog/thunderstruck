#include <QApplication>
#include "MainWindow.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	Jeu jeu("John Doe");
	jeu.tour().player().set_argent(1000);
	MainWindow win(&jeu);

	win.show();
	return app.exec();
}
