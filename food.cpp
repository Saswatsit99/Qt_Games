#include"food.h"
#include<Qbrush>
Food::Food(QGraphicsItem *parent)
{
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
