#ifndef ITEM_H
#define ITEM_H

#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Item : public QGraphicsRectItem
{
public:
    Item() = default;
    Item(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);

    ~Item();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // ITEM_H
