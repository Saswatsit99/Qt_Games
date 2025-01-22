#ifndef SNAKEBODY_CPP
#define SNAKEBODY_CPP
#include"snakebody.h"
#include<QBrush>
#endif // SNAKEBODY_CPP

SnakeBody::SnakeBody(QGraphicsItem *parent)
{
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
