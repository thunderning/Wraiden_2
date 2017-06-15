#include "Bullet.h"



void Bullet::setPath(QGraphicsItemAnimation * p)
{
	path = p;
}

QGraphicsItemAnimation * Bullet::getPath()
{
	return path;
}

int Bullet::get_damage()
{
	return damage;
}

Bullet::Bullet(QPixmap & p, int dmg)
{
	pic = p;
	damage = dmg;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
