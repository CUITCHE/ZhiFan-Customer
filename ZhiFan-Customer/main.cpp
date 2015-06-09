#include "stdafx.h"
#include "TerminalWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TerminalWidget w({ 800, 600 });
	w.show();
	return a.exec();
}
