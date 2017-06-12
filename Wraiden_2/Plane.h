#ifndef PLANE_H
#define PLANE_H
#include "Item.h"
class Plane :
	public Item
{
protected:
	int life;  //生命       
	int move_speed=10;  //移动速度，每次计数移动多少PX，值越小速度越慢
	int bullet;  //子弹序号
public:
	Plane();
	~Plane();
	//Bullet launch_bullet();
	int get_life();
	int get_speed();
	int change_life(int dmg);
	void flesh_bullet();
};

#endif // PLANE_H
