#include "Item.h"



void Item::deleteItem()
{
	exist = false;
}

bool Item::is_exist()
{
	return exist;
}

void Item::setQuality(int q)
{
	quality = q;
}

int Item::getQuality()
{
	return quality;
}

bool Item::check_out(int w,int h)
{
	QPointF t = this->pos();
	int a = pic.width();
	int b = pic.height();
	if (t.x() < 0 || t.x() + pic.width() > w || t.y() < 0 || t.y() + pic.height() > h)
		return false;
	else return true;
}

void Item::deleteit()
{
	exist = false;
}

QPixmap Item::pixmap()
{
	return pic;
}

QRectF Item::boundingRect() const
{
	return QRectF(0, 0, pic.width(), pic.height());
}

void Item::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawPixmap(0, 0, pic);
}

Item::Item()
{
}

Item::Item(QPixmap & p)
{
	pic=p;
}


Item::~Item()
{
}
