#ifndef COMMENTBOARD_H
#define COMMENTBOARD_H
/*!
 * \file CommentBoard.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 评论显示区，没有楼中楼
 * 对于一条评论，有“举报、感谢、赞”
 * 
 */
#include <QWidget>

class CommentBoardPrivate;

class CommentBoard : public QWidget
{
	Q_OBJECT

public:
	CommentBoard(QWidget *parent = 0);
	~CommentBoard();
	void addItem(const QString &text, const QString &responserName);
protected:
	void initWidget();
	CommentBoardPrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(CommentBoard);
};

#endif // COMMENTBOARD_H
