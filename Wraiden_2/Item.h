#ifndef ITEM_H
#define IIEM_H
#include <QGraphicsPixmapItem>
#include <QPainter>
//#include "Wraiden_2.h"
class Item :
	public QGraphicsPixmapItem
{
protected:
	//int X, Y;  //�������꣬�����Ͻ�Ϊ׼��������item.Pos()����
	//int length, height;  //ͼ����С��������pic.width��pic.height����
	//QPixmap pic;	//����ͼ����������this->pixmap()����
	bool exist;  //�Ƿ񻹴���
	int quality;  //��������
public:
	bool is_exist();
	bool check_out(int w, int h);  //������
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Item();
	Item(QPixmap &p);
	~Item();
};
#endif

