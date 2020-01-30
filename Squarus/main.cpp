#include "Squarus.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Squarus w;
	w.show();
	return a.exec();
}
