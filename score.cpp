#include"score.h"
Score::Score(QGraphicsItem  *parent)
{
    point=0;
    setPlainText(QString("Score: ")+QString::number(point));
}
