#include<snakehead.h>
#include<QBrush>
#include"food.h"
#include"snakebody.h"
#include"snake.h"
#include<set>
extern Snake *snake;
#include<QDebug>
#include<QTimer>
#include<QAbstractEventDispatcher>
#include"display.h"
static int count =0;

SnakeHead::SnakeHead(QGraphicsItem *parent)
{
    Display * body= new Display();
    body->setPos(0,0);
    snake->scene->addItem(body);
    prevKeyEvent='d';
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);


    setFlag(QGraphicsItem::ItemIsFocusable,true);

    SnakeBody *body1=new SnakeBody();
    body1->setPos(0,50);
    snake->scene->addItem(body1);
    snakebody.prepend(body1);
    snakeset.insert(body1);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveSnake()));
    timer->start(120); // Move every 100 milliseconds (adjust as needed)
}
void SnakeHead::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key()==Qt::Key_Up&& prevKeyEvent!='s')
    {
        prevKeyEvent='w';
    }
    else if(keyEvent->key()==Qt::Key_Down&& prevKeyEvent!='w')
    {
        prevKeyEvent='s';
    }
    else if(keyEvent->key()==Qt::Key_Right&& prevKeyEvent!='a')
    {
        prevKeyEvent='d';
    }
    else if(keyEvent->key()==Qt::Key_Left&& prevKeyEvent!='d')
    {
        prevKeyEvent='a';
    }
}

void SnakeHead::expandLength()
{

    SnakeBody * body= new SnakeBody();
    snakebody.prepend(body);
    snakeset.insert(body);
    body->setPos(-200,-200);
    snake->scene->addItem(body);
}

void SnakeHead::moveSnake()
{int x,y;
    if(prevKeyEvent=='w')
    {
        prevPos=pos();
        x=pos().x();
        y=pos().y()+450;
        y%=500;
        setPos(x,y);
    }
    else if(prevKeyEvent=='s')
    {
        prevPos=pos();
        x=pos().x();
        y=pos().y()+50;
        y%=500;
        setPos(x,y);
    }
    else if(prevKeyEvent=='d')
    {
        prevPos=pos();
        x=pos().x()+50;
        y=pos().y();
        x%=500;
        setPos(x,y);
    }
    else if(prevKeyEvent=='a')
    {
        prevPos=pos();
        x=pos().x()+450;
        y=pos().y();
        x%=500;
        setPos(x,y);
    }
qDebug() <<prevKeyEvent<<"\n";
 qDebug() <<snake->f1->x()<<" "<<snake->f1->y()<<"\n";
    if(this->pos()==snake->f1->pos())
    {
        std::set<std::pair<int,int>> s;
        int n=snakebody.size();
        for(int j=0;j<n;j++)
        {
            s.insert({snakebody[j]->x(),snakebody[j]->y()});
        }
        s.insert({this->x(),this->y()});
        int x=rand()%500,y=rand()%500;
        x=(x/50)*50;y=(y/50)*50;
        while(s.find({x,y})!=s.end())
        {
            y=(y+((x+250)/500))%500;
            y=(y/50)*50;
            x=(x+250)%500;
        }
        snake->newFood({x,y});
        snake->updateScore();
        expandLength();
    }
    int n=snakebody.size();
    for(int i=0;i<n-1;i++)
    {
        snakebody[i]->setPos(snakebody[i+1]->pos());
    }
    snakebody.last()->setPos(prevPos);
    std::set<std::pair<int,int>> s;
    int t=snakebody.size();
    for(int j=0;j<t;j++)
    {
        s.insert({snakebody[j]->x(),snakebody[j]->y()});
    }
    if(s.find({x,y})!=s.end())
        timer->stop();
}
