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

class PublishBriefOneEntity;
class ZhiFanBriefFramePrivate;

class ZhiFanBriefFrame : public QWidget
{
	Q_OBJECT

public:
	ZhiFanBriefFrame(const PublishBriefOneEntity *entity, QWidget *parent = 0);
	~ZhiFanBriefFrame();
	void setImageCarouselState(bool on = true);
	void initWidget();
protected slots:
	void onImageLookDetailed();
	void onAnimationShowFinished();
	void onAnimationHideFinished();
protected:
	void initStyle();
	void parseImageData();
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
signals:
	/// @brief ����鿴��ť�������źţ�����֪��id
	// 
	void havealook(const PublishBriefOneEntity *);
protected:
	ZhiFanBriefFramePrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(ZhiFanBriefFrame);
	const PublishBriefOneEntity *entity;
};

#endif // ZHIFANBRIEFFRAME_H
