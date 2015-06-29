#ifndef IMAGECAROUSELFRAME_H
#define IMAGECAROUSELFRAME_H
/*!
 * \file ImageCarouselFrame.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 可以轮播图片，附带动画效果
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
	 @param: on 是否启动图片轮播
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
	//从上到下
	void fromTopToBottom();
	//从下到上
	void fromBottomToTop();
	//从左到右
	void fromLeftToRight();
	//从右到左
	void fromRightToLeft();
private:
	QVector<QLabel*> *labels;
	QTimer *timer;
	int index = 0;
	QPropertyAnimation *animation;
	QSize labelSize;
};

#endif // IMAGECAROUSELFRAME_H
