#include "MyPlane.h"



QRectF MyPlane::boundingRect() const
{
	return QRectF(0, 0, pic.width(), pic.height());
}

void MyPlane::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawPixmap(0, 0, pic);
}

MyPlane::MyPlane(QPixmap &p, int lf, int bulletnum)
{
	pic=p;
	this->life = lf;
	this->bullet = bulletnum;
}

MyPlane::MyPlane()
{
}


MyPlane::~MyPlane()
{
}
