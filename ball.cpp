#include "ball.h"
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "block.h"
#include "gameover.h"
#include "player.h"
Ball::Ball(Player *player) // pass the player as a varriable to be able to call the scoring functions from the same object in screen
    : velocityX(5) // initialize the change of speed in the x direction for movement as positive 5
    , velocityY(-5) // initalize the change of speed in the y axis for movement as negative 5 to go up
{
    QPixmap pix(":/images/Bullet.png");
    setPixmap(pix.scaled(25, 25));
    setPos(375, 475); // positrion in half middle bottom
    this->player = player; // set the player varriable as
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move())); // create connect slot that basically keeps onm calling slot move untill time is up
    timer->start(50); // every 50 miliseconds it is called
}
void Ball::restartGame()
{
    setPos(375, 475); // resets position as initiale and reiniatilises velocity varr
    velocityX = 5;
    velocityY = -5;
}

void Ball::move()
{
    setPos(x() + velocityX, y() + velocityY); // set position every 50 miliseconds to the position in addition to the velocity rate
    QList<QGraphicsItem *> collidingItemsList = collidingItems(); // check for collisions

    for (int i = 0; i < collidingItemsList.size(); i++) { // for loop to iterate arround all objects collided with
        if (typeid(*(collidingItemsList[i])) == typeid(Player)) { // if it is a player we are going to set velocity to its negation in order to move in the opposite direction
            velocityX = -velocityX;
            velocityY = -velocityY;
        } else if (typeid(*(collidingItemsList[i])) == typeid(Block)) { // if it is a block same as player but we delete items collided with, and call on player object function to increase score
            delete collidingItemsList[i];
            velocityY = -velocityY;
            player->increase();
        }
    }

    if (pos().x() <= 0 || pos().x() + pixmap().width() >= scene()->width()) // to check if it hits the 3 walls except for the players part, move the opposite direction
        velocityX = -velocityX;

    if (pos().y() <= 0 || pos().y() + pixmap().height() >= scene()->height()) {
        velocityY = -velocityY;
    }

    if (pos().y() > player->pos().y()) { // if it exceeds the player position marking a loss
        restartCount++; // counter to see how much time did the player loose

        if (restartCount >= 3) { // if he lost more than three times then it is game over
            // Hide the game scene directly
            QGraphicsScene *currentScene = scene();
            if (currentScene) {
                // Hide the scene by setting its visibility to false
                currentScene->setSceneRect(0, 0, 0, 0); // Optionally adjust scene rect
                currentScene->clear(); // Clear the scene content
            }

            // Show game over screen or perform other actions
            GameOver *gameOverScreen = new GameOver;
            gameOverScreen->show();
        }
        else {

            restartGame(); // else reset the game as if nothing happened
        }
    }
}
