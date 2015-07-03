#ifndef COMMENTBOARDITEM_H
#define COMMENTBOARDITEM_H
/*!
 * \file CommentBoardItem.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * \brief 评论展示的item项 类
 * 对于一条评论，有“举报、感谢、赞”
 * 布局：两行
 * 第一行：评论（即回答）
 * 第二行：回答者的名字、感谢、赞、举报
 * 第三行，不确定。每个item之间会有分割线，但如果是在一行的末尾就没有分割线，
 * 通过setLastoneOfPage设置
 */
#include <QWidget>
class CommentBoardItemPrivate;

class CommentBoardItem : public QWidget
{
	Q_OBJECT

public:
	CommentBoardItem(QWidget *parent = 0);
	~CommentBoardItem();
	void setResponserName(const QString &name);
	void setCommentContext(const QString &text);
	void setLine();
protected:
	void initWidget();
	void initStyle();
	CommentBoardItemPrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(CommentBoardItem);
};

#endif // COMMENTBOARDITEM_H
