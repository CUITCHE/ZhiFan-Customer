#include "stdafx.h"
#include "ImageCarouselFrame.h"
#include "MaskFrame.h"
#include "ZhiFanBriefFrame.h"
#include "PublishBriefOneEntity.h"
#include "Utils.h"
#include "TerminalWidget.h"
#include <QtWidgets/QApplication>
#include <QWebView>
void test(){
	
	TerminalWidget *w = new TerminalWidget(QSize{ 1366, 800 });
	w->show();
}

void test2(){
	QWebView *view = new QWebView;
	view->load(QUrl("http://127.0.0.1/user-center.html"));
	view->show();
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	test();
	return a.exec();
}
