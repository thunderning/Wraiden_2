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
	int launch_speed = 5;  //ÿ���ٸ�20ms����һö�ӵ�
public:
	Plane();
	~Plane();
	//Bullet launch_bullet();
	int get_life();
	int get_speed();
	int get_launchSpeed();
	int get_bullet();
	void set_bullet(int blt);
	void set_lauchSpeed(int spd);
	int change_life(int dmg);
	void flesh_bullet();
};

#endif // PLANE_H
