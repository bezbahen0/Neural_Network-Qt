#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <vector>

class QPushButton;
class QGraphicsScene;
class QGraphicsView;
class QVBoxLayout;
class QHBoxLayout;
class QRectItem;
class GraphicsView;
class QGraphicsRectItem;
class File;
class Network;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(const int x, const int y, QWidget* parent = nullptr);

private slots:
    void clear();
    void recognition();
    void train();

private:
    void initScene();
    void createVectorInputs();

    int x;
    int y;
    QPushButton* clearButton;
    QPushButton* trainingButton;
    QPushButton* recognitionButton;
    QGraphicsScene* scene;
    GraphicsView* view;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonsLayout;

    File* file;
    Network* net;
    QString result;
    std::vector<double> inputs;
    std::vector<double> results;
    std::vector<std::vector<QGraphicsRectItem*>> inputsT;

};

#endif // MAINWINDOW_H
