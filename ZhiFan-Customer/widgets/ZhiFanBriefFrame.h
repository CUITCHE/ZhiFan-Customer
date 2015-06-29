#ifndef ZHIFANBRIEFFRAME_H
#define ZHIFANBRIEFFRAME_H
/*!
 * \file ZhiFanBriefFrame.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 单张知返的简约展示版
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
	/// @brief 点击查看按钮，发射信号，传出知返id
	// 
	void havealook(int publishId);
private:
	const PublishBriefOneEntity *entity;
	unique_ptr<QVBoxLayout> mainLayout;
	QVector<QImage> imageData;
	MaskFrame *maskFrame;	//遮罩，有查看按钮
	QPropertyAnimation *animationShow = 0;
	QPropertyAnimation *animationHide = 0;

	//row1
	QLabel *publisherHeaderImage;	//发布者头像
	QLabel *publisherName;			//用户简称（何先生等）
	QLabel *responseNum;			//回答数
	//row2
	ImageCarouselFrame *imageShow;	//显示图片，一张图片
	//row3
	QLabel *describeMsg;	//描述的节约信息
	//row4
	QLabel *responseMuchOfAppluad;	//被点赞最多的回答，扼要信息

};

#endif // ZHIFANBRIEFFRAME_H
