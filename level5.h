#ifndef LEVEL5_H
#define LEVEL5_H
#include "ball.h"
#include "player.h"
#include "block.h"
#include "gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "levelbase.h"
class Level5: public LevelBase
{
    Q_OBJECT
public:
    explicit Level5(QObject *parent = nullptr);

    void initializeLevel() override;
private:
    Player* player;
    Ball* ball;
    Block* block;
    int blocknumber = 20;
};


#endif // LEVEL5_H
