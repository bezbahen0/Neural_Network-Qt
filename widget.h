#ifndef WIDGET_H
#define WIDGET_H


#include "ui_widget.h"
#include "file.h"
#include "network.h"
#include "item.h"
#include <QString>
#include <vector>
#include <QGraphicsView>
#include <QVector>

namespace Ui {
class Widget;
}

static File file("data.txt");
static Network net(file.getLayout());

class Widget : public QGraphicsView
{
    Q_OBJECT
public:
    Widget(int x, int y);
    ~Widget();
protected:
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_clear_clicked();

    void on_predict_clicked();

    void on_training_clicked();

private:
    int x;
    int y;

    QGraphicsScene* scene = nullptr;
    Ui::Widget *ui;
    QVector<QVector<Item*>> inputsT;
    std::vector<double> inputs;
    std::vector<double> results;
    QString result;
    QString inp = "";
    void new_scene();
    void create_vector_inputs();
    void recognition_function();
    void result_push();
    void training_f();
};


#endif // WIDGET_H
