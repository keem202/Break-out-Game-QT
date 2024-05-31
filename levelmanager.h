#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QObject>
#include <QList>
#include "levelbase.h"

class LevelManager : public QObject
{
    Q_OBJECT

public:
    explicit LevelManager(QObject *parent = nullptr);

    void addLevel(LevelBase *level); // Add a level to the manager
    void start(); // Start the first level

signals:
    void gameCompleted();

private slots:
    void handleLevelCompleted();

private:
    QList<LevelBase *> levels;
    int currentLevelIndex;
};

#endif // LEVELMANAGER_H
