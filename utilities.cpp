#include "utilities.h"
#include <QMessageBox>


void utilities::warning() {
    QMessageBox::critical(nullptr,"Ошибка","Введите число больше нуля");
}

