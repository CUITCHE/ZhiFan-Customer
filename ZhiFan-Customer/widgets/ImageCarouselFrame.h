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

class ImageCarouselFramePrivate;

class ImageCarouselFrame : public QWidget
{
	Q_OBJECT

public:
	ImageCarouselFrame(QWidget *parent = 0);
	~ImageCarouselFrame();

	/*
	 @param: on 是否启动图片轮播
	*/
	void setTimerOn(bool on = true);
	/*
	 @param frameSize 图片显示的大小
	 @brief 得在生成之前初始化，不然不行
	 */
	static void setFrameSize(const QSize &frameSize);

	void initWidget(const QVector<QPixmap> *imageData);
protected:
	void startAnimation();
	/*void resizeEvent(QResizeEvent *event);*/
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
protected:
	ImageCarouselFramePrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(ImageCarouselFrame);
};

#endif // IMAGECAROUSELFRAME_H
