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
    static void drawSubsidiaries(int x,int y,QGraphicsScene* scene = nullptr);
    static void deleteDrawSubsidiaries(QGraphicsScene* scene);
};

#endif // UTILITIES_H
