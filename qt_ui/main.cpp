#include <QApplication>
#include <QMainWindow>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	QMainWindow win;

	win.setWindowTitle("Thunderstruck");
	win.setMinimumSize(500, 500);
	win.setFixedSize(700, 800);
	win.show();
	return app.exec();
}
