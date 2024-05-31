#include "level2.h"

Level2::Level2(QObject *parent) : LevelBase(parent)
{

}

void Level2::initializeLevel() {
    QGraphicsScene *scene = getScene();
    scene->setSceneRect(0, 0, 800, 600);

    // Create a new Player object
    player = new Player();

    // Allow the player item to receive keyboard focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // Set focus to the player item
    player->setFocus();

    // Add the player item to the scene
    scene->addItem(player);

    // Loop to create blocks (5 rows x 10 columns)
    for (int i = 0; i < 5+blocknumber; i++) {
        for (int j = 0; j < 10; j++) {
            qreal blockX = j * 80;  // Calculate x-coordinate for block
            qreal blockY = i * 20;  // Calculate y-coordinate for block
            block = new Block(blockX, blockY); // Create a new Block object
            scene->addItem(block);   // Add the block to the scene
        }
    }

    // Create a new Ball object with the player as its parent
    ball = new Ball(player);
    // Add the ball to the scene
    scene->addItem(ball);


    emit levelCompleted();
}
