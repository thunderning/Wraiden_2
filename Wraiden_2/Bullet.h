#ifndef BULLET_H
#define BULLET_H
#include "Plane.h"
#include <QGraphicsItemAnimation>
class Bullet :
	public Item
{
protected:
	int damage;  //�˺�      
	//int speed;  //�ٶȣ�ÿx�μ����ƶ�һ��ֵԽ���ٶ�Խ��  !!��animation����
	//int from;  //�ӵ�Դͷ��0��ʾ�ҷ���1��ʾ�з�     !!��item::quality����
	//int direction;  //���� 1 ���ϣ� 2 ���ϣ� 3 ���ϣ�  !!��animation����
					//    -1 ���£�-2 ���£�-3 ���£�
	QGraphicsItemAnimation *path;
public:
	void setPath(QGraphicsItemAnimation *p);
	QGraphicsItemAnimation * getPath();
	bool fly_by_direction(int k, int l, int h);
	void change_xy(int px, int py);
	int get_speed();
	int get_damage();
	//int set(int t, vector<vector<char>>& output, vector<vector<int>>& quality, vector<vector<int>>& source);
	Bullet(int dmg, int spd, int frm, int drt, int x, int y, int len, int hei, char *p);
	Bullet();
	~Bullet();
};

#endif
