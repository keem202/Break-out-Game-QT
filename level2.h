#ifndef LEVEL2_H
#define LEVEL2_H
#include "ball.h"
#include "player.h"
#include "block.h"
#include "gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelbase.h"
class Level2 : public LevelBase
{
    Q_OBJECT
public:
    explicit Level2(QObject *parent = nullptr);

    void initializeLevel() override;
private:
    Player* player;
    Ball* ball;
    Block* block;
    int blocknumber = 5;
};


#endif // LEVEL2_H
