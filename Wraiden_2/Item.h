#ifndef ITEM_H
#define IIEM_H
#include <QGraphicsPixmapItem>
#include <QPainter>
//#include "Wraiden_2.h"
class Item :
	public QGraphicsPixmapItem
{
protected:
	//int X, Y;  //所在坐标，以左上角为准，！！以item.Pos()代替
	//int length, height;  //图案大小，！！以pic.width和pic.height代替
	//QPixmap pic;	//具体图案，！！以this->pixmap()代替
	bool exist=true;  //是否还存在
	int quality;  //属于哪类
public:
	bool is_exist();
	void setQuality(int q);
	bool check_out(int w, int h);  //检查出界
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Item();
	Item(QPixmap &p);
	~Item();
};
#endif

