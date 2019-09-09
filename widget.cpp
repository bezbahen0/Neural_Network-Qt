#include "widget.h"
#include "item.h"
#include "ui_widget.h"

Widget::Widget(int x, int y) :x(x), y(y), scene(nullptr),
    ui(new Ui::Widget)
{
    ui -> setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_predict_clicked()
{
    if(scene == nullptr)
    {
        new_scene();
    }
    recognition_function();
}

void Widget::on_clear_clicked()
{
    new_scene();
}

void Widget::on_training_clicked()
{
    training_f();
}

void Widget::training_f()
{
    int iteration = 0;
    QMessageBox::about(this, "training", "trainig start");
    std::vector<double> targets;
    while(iteration != file.getMaxIterations())
    {
        inputs = file.getInputs(iteration % file.getDataSize());
        net.feedForward(inputs);

        targets = file.getTargets(iteration % file.getDataSize());
        net.backProp(targets);

        net.getResult(results);

        ++iteration;
    }
    targets.clear();
    QMessageBox::about(this, "training", "training finish");
}

void Widget::new_scene()
{
    scene = new QGraphicsScene(0, 0, ui -> graphicsView -> viewport() -> width(), ui -> graphicsView -> viewport() -> height());
    inputsT.resize(x);
    for(int i = 0; i < x; i++)
    {
        inputsT[i].resize(y);
        for(int j = 0; j < y; j++)
        {
            Item *rec = new Item(0, 0, scene -> sceneRect().width() / (y), scene -> sceneRect().height() / (x));
            scene -> addItem(rec);
            rec -> setPos(i * scene -> width() / (y), j * scene -> height() / (x) );
            inputsT[i][j] = rec;
        }
    }
    ui -> graphicsView -> setScene(scene);
}

void Widget::recognition_function()
{
    create_vector_inputs();
    inp = "";
    for(auto i = inputs.begin(); i != inputs.end(); ++i)
    {
        inp += " ";
        inp += QString::number(*i);
    }
    net.feedForward(inputs);
    net.getResult(results);
    result_push();
    QMessageBox::about(this, "inputs", inp);
    QMessageBox::about(this, "recognition results", result);

    unsigned count = 0;
    result = "";
    for(unsigned i = 0; i != results.size(); ++i)
    {
        result += ' ';
        result += QString::number(results[i]);
        ++count;
    }
    QMessageBox::about(this, " aflajslkf", result);
}

void Widget::result_push()
{
    result = "";
    unsigned temp = 0;
    for(unsigned i = 0; i != results.size(); ++i)
    {
        if(results[i] > results[temp])
            temp = i;
        if(temp == results.size())
            temp = 0;
    }

    result = QString::number(temp);
    result += ' ';
    result += QString::number(results[temp]);
}

void Widget::create_vector_inputs()
{
    inputs.clear();
    for(int i = 0; i != x; ++i)
    {
        for(int j = 0; j != y; ++j)
        {
            if(inputsT[j][i] -> brush().color() == Qt::white)
                inputs.push_back(0);

            if(inputsT[j][i] -> brush().color() == Qt::black)
                inputs.push_back(1);
        }
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    Item* cliced = new Item(0, 0, scene -> sceneRect().width() / event -> y(), scene -> sceneRect().height() / event -> x());
    scene -> addItem(cliced);
    if (cliced -> brush().color() == Qt::white)//itemAt(mapToScene(event->pos()), QTransform()) -> brush().color() == Qt::white)
    {
        cliced -> setBrush(QBrush(Qt::black));
    }
    else
    {
        cliced -> setBrush(QBrush(Qt::white));
    }


//  QPointF p = mapToScene(event->pos());
//  // создает новый элемент
//  auto item = new Item;
//  item->setRect(0,0,50,50);
//  item->moveBy(p.x()-25, p.y()-25);
//  scene -> addItem(item);
//  return;

//    if (cliced -> brush().color() == Qt::white)//itemAt(mapToScene(event->pos()), QTransform()) -> brush().color() == Qt::white)
//    {
//        cliced -> setBrush(QBrush(Qt::black));
//    }
//    else
//    {
//        cliced -> setBrush(QBrush(Qt::white));
//    }
    QGraphicsView::mouseMoveEvent(event);

}
