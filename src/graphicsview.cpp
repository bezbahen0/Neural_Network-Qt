#include "include/graphicsview.h"


GraphicsView::GraphicsView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{

}

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{

}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsRectItem* item = static_cast<QGraphicsRectItem*>(itemAt(event -> pos()));
    if(item == nullptr) return;

    if(QApplication::keyboardModifiers() == Qt::CTRL)
    {
        item -> setBrush(Qt::white);
    }
    else
    {
        item -> setBrush(Qt::black);
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    GraphicsView::mousePressEvent(event);
    QGraphicsView::mouseMoveEvent(event);

}
