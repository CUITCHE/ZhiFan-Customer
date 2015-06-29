#ifndef ZHIFANBRIEFFRAME_H
#define ZHIFANBRIEFFRAME_H
/*!
 * \file ZhiFanBriefFrame.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ����֪���ļ�Լչʾ��
 */

#include <QWidget>
#include <memory>
#include <QImage>
#include <QVector>
using std::unique_ptr;

class PublishBriefOneEntity;
class QVBoxLayout;
class QPushButton;
class QLabel;
class MaskFrame;
class ImageCarouselFrame;
class QResizeEvent;
class QPropertyAnimation;

class ZhiFanBriefFrame : public QWidget
{
	Q_OBJECT

public:
	ZhiFanBriefFrame(const PublishBriefOneEntity *entity, QWidget *parent = 0);
	~ZhiFanBriefFrame();
	void setImageCarouselState(bool on = true);
protected slots:
	void onImageLookDetailed();
	void onAnimationShowFinished();
	void onAnimationHideFinished();
protected:
	void initWidget();
	void parseImageData();
	void resizeEvent(QResizeEvent *event);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
signals:
	/// @brief ����鿴��ť�������źţ�����֪��id
	// 
	void havealook(int publishId);
private:
	const PublishBriefOneEntity *entity;
	unique_ptr<QVBoxLayout> mainLayout;
	QVector<QImage> imageData;
	MaskFrame *maskFrame;	//���֣��в鿴��ť
	QPropertyAnimation *animationShow = 0;
	QPropertyAnimation *animationHide = 0;

	//row1
	QLabel *publisherHeaderImage;	//������ͷ��
	QLabel *publisherName;			//�û���ƣ��������ȣ�
	QLabel *responseNum;			//�ش���
	//row2
	ImageCarouselFrame *imageShow;	//��ʾͼƬ��һ��ͼƬ
	//row3
	QLabel *describeMsg;	//�����Ľ�Լ��Ϣ
	//row4
	QLabel *responseMuchOfAppluad;	//���������Ļش𣬶�Ҫ��Ϣ

};

#endif // ZHIFANBRIEFFRAME_H
