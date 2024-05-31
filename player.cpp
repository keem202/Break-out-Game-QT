#include "player.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "gameover.h"

// Constructor for the Player class
Player::Player()
    : score(0)             // Initialize score member variable to 0
    , playerSpeed(10)      // Set player movement speed to 10 pixels per move
{
    // Load player image from resource file
    QPixmap pix(":/images/Player.png");
    // Scale the player image to 25x25 pixels and set it as the pixmap for the player
    setPixmap(pix.scaled(25, 25));
    // Set initial position of the player on the scene (375, 555)
    setPos(375, 555);

    score = 0; // Initialize score to 0

    // Create a QGraphicsTextItem for displaying the score
    scoreText = new QGraphicsTextItem();
    // Set the text for the score text item
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    // Set the default text color to blue
    scoreText->setDefaultTextColor(Qt::blue);
    // Set the position of the score text item (0, 300) relative to the scene
    scoreText->setPos(0, 300);
    // Add the score text item to the scene
    scene()->addItem(scoreText);
}

// Key press event handler for the Player class
void Player::keyPressEvent(QKeyEvent *event)
{
    // Initialize text properties using helper function
    initializeText(scoreText, "Score: ", Qt::blue, 60, 100, score);

    // Move player left when left arrow key is pressed
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - playerSpeed, y());
        }
    }

    // Move player right when right arrow key is pressed
    if (event->key() == Qt::Key_Right) {
        if (pos().x() + pixmap().width() < scene()->width()) {
            setPos(x() + playerSpeed, y());
        }
    }

    // Update the score text after moving
    updateText();
}

// Update the score text item with the current score
void Player::updateText()
{
    scoreText->setPlainText("Score: " + QString::number(score));
}

// Helper function to initialize a QGraphicsTextItem with specified properties
void Player::initializeText(
    QGraphicsTextItem *textItem, const QString &text, const QColor &color, int x, int y, int T)
{
    textItem->setPlainText(text + QString::number(T)); // Set text with score
    textItem->setDefaultTextColor(color);              // Set text color
    textItem->setPos(x, y);                            // Set position of text item
    scene()->addItem(textItem);                        // Add text item to the scene
}

// Increase the player's score and update the score text item
void Player::increase()
{
    score++; // Increment the score
    scoreText->setPlainText("Score: " + QString::number(score)); // Update score text
}
