#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Block(qreal x, qreal y);
};

#endif // BLOCK_H
