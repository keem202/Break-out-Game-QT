#ifndef LEVEL4_H
#define LEVEL4_H
#include "ball.h"
#include "player.h"
#include "block.h"
#include "gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelbase.h"
class Level4: public LevelBase
{
    Q_OBJECT
public:
    explicit Level4(QObject *parent = nullptr);

    void initializeLevel() override;
private:
    Player* player;
    Ball* ball;
    Block* block;
    int blocknumber = 18;
};


#endif // LEVEL4_H
