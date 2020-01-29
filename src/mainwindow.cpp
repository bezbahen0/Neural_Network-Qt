#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "include/mainwindow.h"
#include "include/graphicsview.h"
#include "include/file.h"
#include "include/network.h"

MainWindow::MainWindow(const int x, const int y, QWidget *parent) : QWidget(parent), x(x), y(y)
{
    clearButton = new QPushButton(tr("clear"));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    recognitionButton = new QPushButton(tr("recognition"));
    connect(recognitionButton, SIGNAL(clicked()), this, SLOT(recognition()));

    trainingButton = new QPushButton(tr("training"));
    connect(trainingButton, SIGNAL(clicked()), this, SLOT(train()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout -> addWidget(clearButton);
    buttonsLayout -> addWidget(recognitionButton);
    buttonsLayout -> addWidget(trainingButton);

    scene = new QGraphicsScene;
    view = new GraphicsView(scene);
    initScene();
    view -> show();

    mainLayout = new QVBoxLayout;
    mainLayout -> addLayout(buttonsLayout);
    mainLayout -> addWidget(view);

    file = new File("data.txt");
    net = new Network(file -> getLayout());

    setLayout(mainLayout);
}

void MainWindow::clear()
{
    if(scene != nullptr)
    {
        delete scene;
    }
    initScene();
}



void MainWindow::recognition()
{
    createVectorInputs();
    net -> feedForward(inputs);
    net -> getResult(results);

    result = "";
    for(unsigned i = 0; i != results.size(); ++i)
    {
        result += '\n';
        result += QString::number(results[i]);
    }
    QMessageBox::about(this, "result", result);
}

void MainWindow::train()
{

    QMessageBox::about(this, "training", "trainig start");
    std::vector<double> targets;
    for(int i = 0; i < file -> getMaxIterations(); ++i)
    {
        inputs = file -> getInputs(i % file -> getDataSize());
        net -> feedForward(inputs);

        targets = file -> getTargets(i % file -> getDataSize());
        net -> backProp(targets);

        net -> getResult(results);
    }
    QMessageBox::about(this, "training", "training finish");
}

void MainWindow::initScene()
{
    scene = new QGraphicsScene(0, 0, view -> viewport() -> width(), view -> viewport() -> height());
    inputsT.resize(x);
    for(int i = 0; i < x; ++i)
    {
        inputsT[i].resize(y);
        for(int j = 0; j < y; ++j)
        {
            QGraphicsRectItem* rec = new QGraphicsRectItem(0, 0, scene -> sceneRect().width() / y, scene -> sceneRect().height() / x);
            rec -> setBrush(QBrush(Qt::white));
            rec -> setPos(i * scene -> width() / y, j * scene -> height() / x);
            scene -> addItem(rec);
            inputsT[i][j] = rec;
        }
    }
    view -> setScene(scene);
}

void MainWindow::createVectorInputs()
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
