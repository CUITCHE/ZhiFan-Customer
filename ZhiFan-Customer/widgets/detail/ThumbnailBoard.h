#ifndef THUMBNAILBOARD_H
#define THUMBNAILBOARD_H
/*!
 * \file ThumbnailBoard.h
 *
 * \author CHE
 * \date 六月 2015
 *
 * 缩略图 显示面板
 */
#include <QWidget>
class ThumbnailBoardPrivate;

class ThumbnailBoard : public QWidget
{
	Q_OBJECT

public:
	/*!
	 * \param ThumbnailImages 外层传入的缩略图
	*/
	ThumbnailBoard(QList<QPixmap> &ThumbnailImages, QWidget *parent = 0);
	~ThumbnailBoard();
signals:
	void clicked(int numberOfLabel);
protected:
	void initWidget(QList<QPixmap> &);

	//ThumbnailBoardPrivate * const d_ptr;
private:
	//Q_DECLARE_PRIVATE(ThumbnailBoard);
}; 

#endif // THUMBNAILBOARD_H
