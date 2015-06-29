#ifndef IMAGEBOARD_H
#define IMAGEBOARD_H
/*!
 * \file ImageBoard.h
 *
 * \author CHE
 * \date ÁùÔÂ 2015
 *
 * Õ¹Ê¾Í¼Æ¬
 */
#include <QWidget>
class ImageBoardPrivate;

class ImageBoard : public QWidget
{
	Q_OBJECT

public:
	ImageBoard(QList<QPixmap> &images, QWidget *parent = 0);
	~ImageBoard();

protected slots:
	void onThumbnailBoardClicked(int tag);
protected:
	void initWidget(QList<QPixmap> &images);

	ImageBoardPrivate * const d_ptr;
private:
	Q_DECLARE_PRIVATE(ImageBoard);
};

#endif // IMAGEBOARD_H
