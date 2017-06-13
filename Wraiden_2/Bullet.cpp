#include "Bullet.h"



void Bullet::setPath(QGraphicsItemAnimation * p)
{
	path = p;
}

QGraphicsItemAnimation * Bullet::getPath()
{
	return path;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
