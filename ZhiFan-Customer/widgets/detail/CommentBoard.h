#ifndef COMMENTBOARD_H
#define COMMENTBOARD_H
/*!
 * \file CommentBoard.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * ������ʾ����û��¥��¥
 * ����һ�����ۣ��С��ٱ�����л���ޡ�
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
