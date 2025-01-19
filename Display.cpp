#include"display.h"
#include<Qbrush>

// to print the out line of the game display
Display::Display(QGraphicsItem *parent)
{
    setRect(0,0,500,500);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}
