#include"snake.h"
#include"snakehead.h"
#include"food.h"
#include<QGraphicsScene>
#include"score.h"
int x=300;
int y=300;
Snake::Snake(QWidget *parent)
{
    scene=new QGraphicsScene(0,0,1000,700);
    setScene(scene);
    view=new QGraphicsView();
    view->setScene(scene);
}

void Snake::start()
{
    SnakeHead * snakehead = new SnakeHead();
    scene->addItem(snakehead);
    snakehead->setFocus();
    f1 = new Food();
    f1->setPos(300,300);
    scene->addItem(f1);
    s1=new Score;
    s1->setPos(500,500);
    scene->addItem(s1);
}

void Snake::newFood(std:: pair<int,int> p)
{
    scene->removeItem(f1);
     f1 = new Food();
    f1->setPos(p.first,p.second);
    scene->addItem(f1);
}

void Snake::updateScore()
{
    s1->point++;
    s1->setPlainText(QString("Score: ")+QString::number(s1->point));
}

