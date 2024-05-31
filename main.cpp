#include "levelmanager.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"

int main()
{
    LevelManager levelManager;

    // Create instances of different levels
    Level1 *level1 = new Level1();
    Level2 *level2 = new Level2();
    Level3 *level3 = new Level3();
    Level4 *level4 = new Level4();
    Level5 *level5 = new Level5();

    // Add levels to the manager
    levelManager.addLevel(level1);
    levelManager.addLevel(level2);
    levelManager.addLevel(level3);
    levelManager.addLevel(level4);
    levelManager.addLevel(level5);

    // Start the game
    levelManager.start();

    return 0;
}
