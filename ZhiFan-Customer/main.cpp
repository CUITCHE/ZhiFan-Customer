#include "stdafx.h"
#include "TerminalWidget.h"
#include "NetCommunicationProtocol.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qDebug() << net::ProtocolToCNString(net::ResponseZhiFan);
	TerminalWidget w({ 800, 600 });
	w.show();
	return a.exec();
}
