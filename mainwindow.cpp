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

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::addNodeToScene() {
    QString nodeValue = inputNodeEdit->text();
    int intNode = nodeValue.toInt();
    TreeNode<int>* newNode = binarySearchTree.insert(intNode);
    int x = newNode->getX();
    int y = newNode->getY();
    int width = 50;
    int height = 50;

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x, y, width, height);

    QGraphicsTextItem* numberNode = new QGraphicsTextItem(nodeValue);

    int centerX = x + width / 2;
    int centerY = y + height / 2;

    QRectF textRect = numberNode->boundingRect();
    int textX = centerX - textRect.width() / 2;
    int textY = centerY - textRect.height() / 2;

    numberNode->setPos(textX, textY);

    scene->addItem(ellipse);
    scene->addItem(numberNode);
}







