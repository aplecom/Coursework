#include "utilities.h"
#include <QMessageBox>

bool utilities::w = false;

void utilities::warningRange() {
    QMessageBox::critical(nullptr,"Неверный диапазон","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
}
void utilities::warningRepeat() {
    QMessageBox::critical(nullptr,"Повторение узла","Требование:\n *тип данных: int\n *больше нуля\n *без повторений");
    w = true;
}

