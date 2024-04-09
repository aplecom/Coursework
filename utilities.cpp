#include "utilities.h"


bool utilities::w = false;

void utilities::warningRange() {
    QMessageBox::critical(nullptr,"Неверный диапазон","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
}
void utilities::warningRepeat() {
    QMessageBox::critical(nullptr,"Повторение узла","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
    w = true;
}
void utilities:: draw(int x,int y, int widthNode  , int heightNode, QGraphicsScene* scene ){
    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x,y,widthNode,heightNode);
    QBrush brush(Qt::lightGray);
    ellipse->setBrush(brush);
    scene->addItem(ellipse);
}

