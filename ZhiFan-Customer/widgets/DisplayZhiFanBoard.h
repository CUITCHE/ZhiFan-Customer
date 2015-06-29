#ifndef DISPLAYZHIFANBOARD_H
#define DISPLAYZHIFANBOARD_H
/*!
 * \file DisplayZhiFanBoard.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ��ʾ����֪����Լ��Ϣ��չʾ��
 * �㷨���ο� http://huaban.com
 */
#include <QWidget>
#include <QList>
#include <memory>

class ZhiFanBriefFrame;
class PublishBriefOneEntity;
class DisplayBoardItemsForColumn;
class QScrollArea;
class QResizeEvent;
class DisplayZhiFanBoardPrivate;

class DisplayZhiFanBoard : public QWidget
{
	Q_OBJECT

public:
	/*
	 @param columns: ��Ҫ���������У�Ĭ��4��
	*/
	DisplayZhiFanBoard(QWidget *parent = 0, int columns = 4);
	~DisplayZhiFanBoard();
	void addItem(const PublishBriefOneEntity *entity);
	void addItems(const QList<PublishBriefOneEntity *> &entities);
protected:
	void initColumnWidget(int columns);
	void resizeEvent(QResizeEvent *event);
protected:
	DisplayZhiFanBoardPrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(DisplayZhiFanBoard);
};

#endif // DISPLAYZHIFANBOARD_H
