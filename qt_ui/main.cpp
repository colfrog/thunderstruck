#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	MainWindow win;

	win.setWindowTitle("Thunderstruck");
	win.setMinimumSize(500, 500);
	win.setFixedSize(700, 800);
	win.show();
	return app.exec();
}
