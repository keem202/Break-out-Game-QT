#include "gameover.h"
#include <QLabel>
#include <QVBoxLayout>

// Constructor definition for GameOver class
GameOver::GameOver(QWidget *parent)
    : QDialog(parent)  // Initialize base class QDialog with parent
{
    QLabel *gameOverLabel = new QLabel("Game Over", this);  // Create QLabel instance with text "Game Over" and set parent
    QFont font("Arial", 24, QFont::Bold);  // Create QFont instance with specified font family, size, and weight
    gameOverLabel->setFont(font);  // Set the font of the QLabel
    gameOverLabel->setAlignment(Qt::AlignCenter);  // Set text alignment of the QLabel to center

    QVBoxLayout *layout = new QVBoxLayout(this);  // Create QVBoxLayout instance with this as parent
    layout->addWidget(gameOverLabel);  // Add the gameOverLabel to the QVBoxLayout
    setLayout(layout);  // Set the layout of the QDialog to the QVBoxLayout
}
