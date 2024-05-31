
#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QLabel>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);


private:
    QLabel *gameOverLabel; // You may need to include QLabel header if not included
};

#endif // GAMEOVER_H
