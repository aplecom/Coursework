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
void MainWindow::addNodeToScene() {
    QString inputValue = inputNodeEdit->text();
    int intValue = inputValue.toInt();

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(0, 0, 50, 50);
    QGraphicsTextItem* textItem = new QGraphicsTextItem(inputValue);
    ellipse->setPos(100, 100);

    qreal xOffset = 100;
    qreal yOffset = 100;

    TreeNode<int>* previousNode = nullptr;

    if (binarySearchTree.getRoot() != nullptr) {
        previousNode = binarySearchTree.getRoot();

        while (true) {
            if (intValue < previousNode->data) {
                if (previousNode->getLeft() == nullptr) {
                    break;
                } else {
                    previousNode = previousNode->getLeft();
                }
            } else {
                if (previousNode->getRight() == nullptr) {
                    break;
                } else {
                    previousNode = previousNode->getRight();
                }
            }
        }

        qreal newX, newY;
        if (intValue < previousNode->data) {
            newX = previousNode->getX() - 100;
            newY = previousNode->getY() + 100;
        } else {
            newX = previousNode->getX() + 100;
            newY = previousNode->getY() + 100;
        }

        ellipse->setPos(newX, newY);
        textItem->setPos(newX + ellipse->rect().width() / 2 - textItem->boundingRect().width() / 2,
                         newY + ellipse->rect().height() / 2 - textItem->boundingRect().height() / 2);
    } else {
        textItem->setPos(ellipse->pos().x() + ellipse->rect().width() / 2 - textItem->boundingRect().width() / 2,
                         ellipse->pos().y() + ellipse->rect().height() / 2 - textItem->boundingRect().height() / 2);
    }

    TreeNode<int>* newNode = binarySearchTree.insert(intValue);
    newNode->setX(ellipse->pos().x());
    newNode->setY(ellipse->pos().y());

    scene->addItem(ellipse);
    scene->addItem(textItem);

    inputNodeEdit->clear();
}




