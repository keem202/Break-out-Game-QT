#include "levelmanager.h"

LevelManager::LevelManager(QObject *parent) : QObject(parent), currentLevelIndex(-1)
{
    connect(this, &LevelManager::gameCompleted, [](){
    });
}

void LevelManager::addLevel(LevelBase *level)
{
    levels.append(level);
    connect(level, &LevelBase::levelCompleted, this, &LevelManager::handleLevelCompleted);
}

void LevelManager::start()
{
    if (levels.isEmpty()) {
        return;
    }

    currentLevelIndex = 0;
    levels[currentLevelIndex]->initializeLevel();
}

void LevelManager::handleLevelCompleted()
{
    currentLevelIndex++;
    if (currentLevelIndex < levels.size()) {
        levels[currentLevelIndex]->initializeLevel();
    } else {
        emit gameCompleted();
    }
}
