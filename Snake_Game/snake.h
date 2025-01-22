#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include"food.h"
#include"score.h"
class Snake: public QGraphicsView
{
public:
    Food * f1;
    Score* s1;
    Snake(QWidget * parent =NULL);

    void start();
    void newFood(std::pair<int,int> p);
    void updateScore();

    QGraphicsScene* scene;
    QGraphicsView *view;
};

#endif // SNAKE_H
