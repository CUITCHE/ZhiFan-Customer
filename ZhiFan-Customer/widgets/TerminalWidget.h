#ifndef TERMINALWIDGET_H
#define TERMINALWIDGET_H
/*!
 * \file TerminalWidget.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 整体界面生成类
 */

#include <QWidget>

class TerminalWidgetPrivate;
class Packet;

class TerminalWidget : public QWidget
{
	Q_OBJECT

public:
	TerminalWidget(const QSize &frame, QWidget *parent = 0);
	~TerminalWidget();
public slots:
	bool sendRequest(const Packet *packet);
	void onPacketData(const Packet *packet);
	void login();
protected slots:
	void onQuit();
	void onMinus();
	void onExtend();
	void onPublishBtnClicked();
protected:
	void initWidget();
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void shadowPaint();
	void setFillet();
	void initStyle();
	TerminalWidgetPrivate * const d_ptr;
	void onServerBack(const Packet *packet);
	void onResponseGetOneZhiFanPublish(const Packet *packet);
	void onResponseGetZhiFanPublishPageOfRange(const Packet *packet);
	void onResponseLogin(const Packet *packet);
	void onResponsePullUserCenter(const Packet *packet);
	void onResponseSearchZhiFan(const Packet *packet);
private:
	Q_DECLARE_PRIVATE(TerminalWidget);
};

#endif // TERMINALWIDGET_H
