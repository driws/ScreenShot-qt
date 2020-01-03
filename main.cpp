#include "mandalorian.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Mandalorian w;
	w.setWindowIcon(QIcon("Resources/starwars.ico"));
	w.show();
	return a.exec();
}
