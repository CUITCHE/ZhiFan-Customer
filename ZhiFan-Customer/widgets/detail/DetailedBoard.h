#ifndef DETAILEDBOARD_H
#define DETAILEDBOARD_H
/*!
 * \file DetailedBoard.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 展示知返详细情况的面板
 */

#include <QDialog>

class DetailedBoardPrivate;
class PublishOneEntity;
class PublishBriefOneEntity;
class QResizeEvent;

class DetailedBoard : public QDialog
{
	Q_OBJECT

public:
	DetailedBoard(const PublishBriefOneEntity *bEntity, const PublishOneEntity *dEntity, QWidget *parent = 0);
	~DetailedBoard();
protected:
	/*!
	 * \brief 初始化界面，只会执行一次
	 */
	void initWidget();

	void parseData();

	void initStyle();
	DetailedBoardPrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(DetailedBoard);
	const PublishOneEntity *entity_d;
	const PublishBriefOneEntity *entity_b;
};

#endif // DETAILEDBOARD_H
