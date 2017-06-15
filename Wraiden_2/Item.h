#ifndef ITEM_H
#define IIEM_H
#include <QGraphicsPixmapItem>
#include <QTimeLine>
#include <QPainter>
#include <QGraphicsObject>
//#include "Wraiden_2.h"
class Item :
	public QGraphicsObject
{
	Q_OBJECT
protected:
	//int X, Y;  //�������꣬�����Ͻ�Ϊ׼��������item.Pos()����
	//int length, height;  //ͼ����С��������pic.width��pic.height����
	QPixmap pic;	//����ͼ����
	bool exist=true;  //�Ƿ񻹴���
	int quality;  //��������
private slots:
	void deleteItem();
public:
	bool is_exist();
	void setQuality(int q);
	int getQuality();
	bool check_out(int w, int h);  //������
	void deleteit();
	QPixmap pixmap();
	QRectF boundingRect()const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	Item();
	Item(QPixmap &p);
	~Item();
};
#endif

