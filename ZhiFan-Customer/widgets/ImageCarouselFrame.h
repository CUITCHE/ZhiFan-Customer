#ifndef IMAGECAROUSELFRAME_H
#define IMAGECAROUSELFRAME_H
/*!
 * \file ImageCarouselFrame.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * �����ֲ�ͼƬ����������Ч��
 */
#include <QWidget>
#include <QVector>
#include <QImage>

class QLabel;
class QTimer;
class QResizeEvent;
class QPropertyAnimation;

class ImageCarouselFrame : public QWidget
{
	Q_OBJECT

public:
	ImageCarouselFrame(const QVector<QImage> &imageData, QWidget *parent = 0);
	~ImageCarouselFrame();

	/*
	 @param: on �Ƿ�����ͼƬ�ֲ�
	*/
	void setTimerOn(bool on = true);
protected:
	void initWidget(const QVector<QImage> &imageData);
	void startAnimation();
	void resizeEvent(QResizeEvent *event);
protected slots:
	void onTimerSwitchImage();
	void onAnimationFinished();
private:
	//���ϵ���
	void fromTopToBottom();
	//���µ���
	void fromBottomToTop();
	//������
	void fromLeftToRight();
	//���ҵ���
	void fromRightToLeft();
private:
	QVector<QLabel*> *labels;
	QTimer *timer;
	int index = 0;
	QPropertyAnimation *animation;
	QSize labelSize;
};

#endif // IMAGECAROUSELFRAME_H
