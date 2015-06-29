#ifndef MASKFRAME_H
#define MASKFRAME_H

#include <QWidget>
class QEvent;
class QPushButton;
class QResizeEvent;
class QLabel;

class MaskFrame : public QWidget
{
	Q_OBJECT

public:
	MaskFrame(QWidget *parent = 0);
	~MaskFrame();
signals:
	void tryToLook();
public slots:
	void onBtnClicked();
	void showOne();
	void showAll();
protected:
	void initWidget();
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void resizeEvent(QResizeEvent *event);
private:
	QPushButton *lookOverBtn;
	QLabel *maskLabel;
};

#endif // MASKFRAME_H
