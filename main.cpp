#include "mainwindow.h"

#include <QApplication>
#include"snake.h"
Snake * snake;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    snake = new  Snake;
    snake->show();
    snake->start();
    return a.exec();
}
