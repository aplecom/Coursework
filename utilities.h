#ifndef UTILITIES_H
#define UTILITIES_H
#include <QMessageBox>
#include<QGraphicsEllipseItem>
#include<QGraphicsScene>
class utilities
{
public:
    static void warningRange();
    static void warningRepeat();
    static bool w;
    static void draw(int x,int y, int widthNode = 80 , int heightNode = 80,QGraphicsScene* scene = nullptr);
    // static void deleteDraw(QGraphicsScene* scene);
    // static std::vector<QGraphicsEllipseItem*> ellipseList;
};

#endif // UTILITIES_H
