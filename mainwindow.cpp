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
    int widthNode = 50;
    int heightNode = 50;

    QString nodeValue = inputNodeEdit->text();
    int intNode = nodeValue.toInt();

    TreeNode<int>* newNode = binarySearchTree.insert(intNode);
    int xNode = newNode->getX();
    int yNode = newNode->getY();

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(xNode, yNode, widthNode, heightNode);
    QGraphicsTextItem* numberNode = new QGraphicsTextItem(nodeValue);

    int xNodeStart = newNode->getPX() + widthNode/2 ;
    int yNodeStart = newNode->getPY() + heightNode;
    int xNodeEnd = xNode + widthNode/2;
    int yNodeEnd;
    if(!lineMove){
         yNodeEnd = yNode + heightNode;
        lineMove = !lineMove;
    }
    else
         yNodeEnd = yNode;

    QGraphicsLineItem* line = new QGraphicsLineItem(xNodeStart,yNodeStart,xNodeEnd,yNodeEnd);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::white);
    line->setPen(pen);


    int centerX = xNode + widthNode / 2;
    int centerY = yNode + heightNode / 2;

    QRectF textRect = numberNode->boundingRect();
    int textX = centerX - textRect.width() / 2;
    int textY = centerY - textRect.height() / 2;

    numberNode->setPos(textX, textY);

    scene->addItem(line);
    scene->addItem(ellipse);
    scene->addItem(numberNode);

}







