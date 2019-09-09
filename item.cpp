#include "item.h"

Item::Item(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):QGraphicsRectItem(x, y, w, h, parent)
{
    setBrush(QBrush(Qt::white));
}

Item::~Item()
{

}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (this -> brush().color() == Qt::white)
    {
        this ->setBrush(QBrush(Qt::black));
    }
    else
    {
        this -> setBrush(QBrush(Qt::white));
    }
}

//void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
//    //Item::mouseMoveEvent(event);

//    //this->setBrush(QBrush(Qt::black));
//}






//void Item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    //Item::mousePressEvent(event);
//    //event->pos().x();
//    //event->pos().y();
//    //QGraphicsItem::mouseMoveEvent(event);
//    //this -> setPos(mapToScene(event -> pos()));
//    //this->setPos(mapToScene(event->pos()));
//    //this -> pos();
//    if(event -> pos().x() <= this -> pos().x() && event -> pos().y() <= this -> pos().y())
//    {
//        if (this -> brush().color() == Qt::white)
//        {
//            this ->setBrush(QBrush(Qt::black));
//        }
//        else
//        {
//            this -> setBrush(QBrush(Qt::white));
//        }
//    }
//    //if (0 <= event -> pos().x() && event ->pos().x() <= this -> width() && 0 <= event ->pos().y() && event -> pos().y() <= this -> height())
//    //GraphicsItem *item = scene.itemAt(mapToScene(event->pos()), QTransform());
//}
