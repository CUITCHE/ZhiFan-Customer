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

class ImageCarouselFramePrivate;

class ImageCarouselFrame : public QWidget
{
	Q_OBJECT

public:
	ImageCarouselFrame(QWidget *parent = 0);
	~ImageCarouselFrame();

	/*
	 @param: on �Ƿ�����ͼƬ�ֲ�
	*/
	void setTimerOn(bool on = true);
	/*
	 @param frameSize ͼƬ��ʾ�Ĵ�С
	 @brief ��������֮ǰ��ʼ������Ȼ����
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
	//���ϵ���
	void fromTopToBottom();
	//���µ���
	void fromBottomToTop();
	//������
	void fromLeftToRight();
	//���ҵ���
	void fromRightToLeft();
protected:
	ImageCarouselFramePrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(ImageCarouselFrame);
};

#endif // IMAGECAROUSELFRAME_H
