#ifndef COMMENTBOARDITEM_H
#define COMMENTBOARDITEM_H
/*!
 * \file CommentBoardItem.h
 *
 * \author CHE
 * \date ���� 2015
 *
 * \brief ����չʾ��item�� ��
 * ����һ�����ۣ��С��ٱ�����л���ޡ�
 * ���֣�����
 * ��һ�У����ۣ����ش�
 * �ڶ��У��ش��ߵ����֡���л���ޡ��ٱ�
 * �����У���ȷ����ÿ��item֮����зָ��ߣ����������һ�е�ĩβ��û�зָ��ߣ�
 * ͨ��setLastoneOfPage����
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
