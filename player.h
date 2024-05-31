#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QTimer>
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void decrease();
    void updateText();
    void initializeText(
        QGraphicsTextItem *textItem, const QString &text, const QColor &color, int x, int y, int T);
    void increase();

private:
    int score;
    int playerSpeed;
    QGraphicsTextItem *scoreText;
};

#endif // PLAYER_H
