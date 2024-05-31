#include "block.h"

Block::Block(qreal x, qreal y) // initializes game object by ascribing an image to it and position x y passed as parameters
{
    QPixmap pix(":/images/block.png");
    setPixmap(pix.scaled(20, 20));
    setPos(x, y);
}
