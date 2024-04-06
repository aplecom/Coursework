#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BinarySearchTree.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputNodeEdit = new QLineEdit(this);
    addNodeBtn = new QPushButton("Добавить", this);
    setStyleButton(addNodeBtn);
    setStyleLineEdit(inputNodeEdit);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(inputNodeEdit);
    layout->addWidget(addNodeBtn);

    QWidget* addNodeWidget = new QWidget(this);
    addNodeWidget->setLayout(layout);

    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::black);
    QGraphicsView* graphicsView = new QGraphicsView(scene, this);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    setupGraphicsView(graphicsView);

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
    int widthNode = 80;
    int heightNode = 80;

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
    pen.setWidth(2);
    pen.setColor(Qt::white);
    line->setPen(pen);
    pen.setColor(Qt::green);
    ellipse->setPen(pen);

    QFont font = numberNode->font();
    font.setBold(true);
    font.setPointSize(font.pointSize()+4);
    numberNode->setFont(font);

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

void MainWindow::setStyleButton(QPushButton *button) {
    button->setStyleSheet("QPushButton {"
                          "border-radius: 10px;"
                          "padding: 10px;"
                          "border: 2px solid orange;" // Цвет границы по умолчанию (красный)
                          "color: white;"
                          "}"
                          "QPushButton:pressed {"
                          "border: 2px solid yellow;" // Цвет фона при нажатии (серый)

                          "}");
}

void MainWindow::setStyleLineEdit(QLineEdit *lineEdit) {
    lineEdit->setStyleSheet("QLineEdit {"
                            "border: 2px solid orange;"
                            "border-radius: 10px;"
                            "padding: 10px;"
                            "color: white;"
                            "background-color: black;"
                            "}"
                            "QLineEdit:hover {"
                            "border: 2px solid yellow;"
                            "}"
                            );
}

void MainWindow::setupGraphicsView(QGraphicsView *graphicsView) {
    graphicsView->setStyleSheet("QGraphicsView {"
                                "border: 1px solid orange;"
                                "}");
}




