#ifndef PLANE_H
#define PLANE_H
#include "Item.h"
class Plane :
	public Item
{
protected:
	int life;  //����       
	int move_speed=10;  //�ƶ��ٶȣ�ÿ�μ����ƶ�����PX��ֵԽС�ٶ�Խ��
	int bullet;  //�ӵ����
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
