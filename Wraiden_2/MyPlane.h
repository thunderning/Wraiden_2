#pragma once
#include "Plane.h"
class MyPlane :
	public Plane
{
public:
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	MyPlane(QPixmap &p);
	MyPlane();
	~MyPlane();
};
