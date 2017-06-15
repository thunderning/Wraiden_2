#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "Plane.h"
#include <QGraphicsItemAnimation>
class EnemyPlane :
	public Plane
{
protected:
	int damage;  //×²»÷ÉËº¦     
	QGraphicsItemAnimation *path;
public:
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	void setPath(QGraphicsItemAnimation *p);
	QGraphicsItemAnimation * getPath();
	int get_damage();
	EnemyPlane(QPixmap &p, int lf, int bulletnum, int dmg);
	EnemyPlane();
	~EnemyPlane();
};

#endif
