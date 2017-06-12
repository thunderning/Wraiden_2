#include "Item.h"



bool Item::check_out(int w,int h)
{
	QPointF t = this->pos();
	int a = pixmap().width();
	int b = pixmap().height();
	if (t.x() < 0 || t.x() + pixmap().width() > w || t.y() < 0 || t.y() + pixmap().height() > h)
		return false;
	else return true;
}

QRectF Item::boundingRect() const
{
	return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void Item::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawPixmap(0, 0, pixmap());
}

Item::Item()
{
}

Item::Item(QPixmap & p)
{
	setPixmap(p);
}


Item::~Item()
{
}
