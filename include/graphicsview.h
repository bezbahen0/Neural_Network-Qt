#ifndef ITEM_H
#define ITEM_H

#include <QtWidgets>

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene* scene, QWidget* parent = nullptr);
    GraphicsView(QWidget* parent = nullptr);
    ~GraphicsView();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

};
#endif // ITEM_H
