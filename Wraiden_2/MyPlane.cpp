#include "MyPlane.h"



QRectF MyPlane::boundingRect() const
{
	return QRectF(0, 0, pixmap().width(), pixmap().height());
}

void MyPlane::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawPixmap(0, 0, pixmap());
}

MyPlane::MyPlane(QPixmap & p)
{
	setPixmap(p);
}

MyPlane::MyPlane()
{
}


MyPlane::~MyPlane()
{
}
