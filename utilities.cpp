#include "utilities.h"

bool utilities::w = false;
std::vector<QGraphicsEllipseItem*> ellipseList;


void utilities::warningRange() {
    QMessageBox::critical(nullptr,"Неверный диапазон","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
}
void utilities::warningRepeat() {
    QMessageBox::critical(nullptr,"Повторение узла","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
    w = true;
}
void utilities:: draw(int x,int y, QGraphicsScene* scene ){
    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x,y,80,80);
    ellipseList.push_back(ellipse);

    QLinearGradient gradient(x, y, x + 80, y + 80);
    gradient.setColorAt(0, QColor(211, 211, 211, 100));
    gradient.setColorAt(1, QColor(211, 211, 211, 255));
    QBrush brush(gradient);
    QPen pen(Qt::green);

    ellipse->setBrush(brush);
    ellipse->setPen(pen);
    scene->addItem(ellipse);
}
void utilities::deleteDraw(QGraphicsScene* scene){
    for(auto ellipse:ellipseList)
    {
       scene->removeItem(ellipse);
       delete ellipse;
    }
    ellipseList.clear();
}


