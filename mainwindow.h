#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QWidget>
#include<QGraphicsView>
#include<QGraphicsTextItem>
#include<QGraphicsLineItem>
#include<QStyle>
#include "BinarySearchTree.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setStyleButton(QPushButton* button);
    void setStyleLineEdit(QLineEdit *lineEdit);
    void setGraphicsView(QGraphicsView *graphicsView);

private slots:
    void addNodeToScene();

    void countNodesWithTwoChildren();

private:
    Ui::MainWindow *ui;
    QLineEdit* inputNodeEdit;
    QPushButton* addNodeBtn;
    QGraphicsScene* scene;
    BinarySearchTree<int> binarySearchTree;
    bool lineMove = false;
    QPushButton* searchBtn;
    int chekingInput(QString input);

};
#endif // MAINWINDOW_H
