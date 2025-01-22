#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H
#include<QgraphicsRectItem>
#include<QPointF>
#include<QList>
#include<QSet>
#include<QKeyEvent>
#include"snakebody.h"
#include<QObject>
#include<QTimer>
#include<QAbstractEventDispatcher>
class SnakeHead:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    SnakeHead(QGraphicsItem * parent=NULL);
   // ~SnakeHead();
    void keyPressEvent(QKeyEvent * keyEvent);
    void expandLength();
    QTimer * timer;
public slots:
    void moveSnake();
private:
    QList<SnakeBody*> snakebody;
    QSet<SnakeBody*> snakeset;
    QPointF prevPos;
    int prevKeyEvent;


};

#endif // SNAKEHEAD_H
