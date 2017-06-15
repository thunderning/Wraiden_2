#ifndef ITEM_H
#define IIEM_H
#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QPainter>
#include <QGraphicsObject>
//#include "Wraiden_2.h"
class Item :
	public QGraphicsObject
{
	Q_OBJECT
protected:
	//int X, Y;  //所在坐标，以左上角为准，！！以item.Pos()代替
	//int length, height;  //图案大小，！！以pic.width和pic.height代替
	QPixmap pic;	//具体图案，
	bool exist=true;  //是否还存在
	int quality;  //属于哪类
private slots:
	void deleteItem();
public:
	bool is_exist();
	void setQuality(int q);
	int getQuality();
	bool check_out(int w, int h);  //检查出界
	void deleteit();
	QPixmap pixmap();
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Item();
	Item(QPixmap &p);
	~Item();
};
#endif

