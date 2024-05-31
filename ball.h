#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include "player.h"
class Ball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer *timer;
    int velocityX;
    int velocityY;
    Player *player;
    int restartCount;

public:
    Ball(Player *player);
    void restartGame();
public slots:
    void move();
};

#endif // BALL_H
