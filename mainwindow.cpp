#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BinarySearchTree.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputNodeEdit = new QLineEdit(this);
    addNodeBtn = new QPushButton("Добавить", this);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(inputNodeEdit);
    layout->addWidget(addNodeBtn);

    QWidget* addNodeWidget = new QWidget(this);
    addNodeWidget->setLayout(layout);

    scene = new QGraphicsScene(this);
    QGraphicsView* graphicsView = new QGraphicsView(scene, this);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(addNodeWidget);
    mainLayout->addWidget(graphicsView);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(addNodeBtn,&QPushButton::clicked,this,&MainWindow::addNodeToScene);

}

MainWindow::~MainWindow()
{
    delete ui;
}
// Метод для добавления узла на сцену при нажатии на кнопку
void MainWindow::addNodeToScene() {

}





