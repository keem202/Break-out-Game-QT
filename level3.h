#ifndef LEVEL3_H
#define LEVEL3_H
#include "ball.h"
#include "player.h"
#include "block.h"
#include "gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelbase.h"
class Level3: public LevelBase
{
    Q_OBJECT
public:
    explicit Level3(QObject *parent = nullptr);

    void initializeLevel() override;
private:
    Player* player;
    Ball* ball;
    Block* block;
    int blocknumber = 15;
};


#endif // LEVEL3_H
