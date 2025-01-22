#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsTextItem>
class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=NULL);
    int point;
};
#endif // SCORE_H
