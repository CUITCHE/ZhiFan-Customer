#include "stdafx.h"
#include "ImageCarouselFrame.h"
#include "MaskFrame.h"
#include "ZhiFanBriefFrame.h"
#include "PublishBriefOneEntity.h"
#include "Utils.h"
#include "TerminalWidget.h"
#include <QtWidgets/QApplication>
void test(){
	TerminalWidget *w = new TerminalWidget(QSize{1024,600});
	w->show();
}

void test2(){
	QString str = QString("�ҽ�%1������%2��").arg("����").arg(18);
	qDebug() << str;
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test();
	return a.exec();
}
