#ifndef DISPLAYZHIFANBOARD_H
#define DISPLAYZHIFANBOARD_H
/*!
 * \file DisplayZhiFanBoard.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 显示所有知返简约信息的展示板
 * 算法：参考 http://huaban.com
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
	 @param columns: 需要建立多少列，默认4列
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
