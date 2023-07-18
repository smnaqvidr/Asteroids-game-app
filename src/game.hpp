/**
*   @brief      directive game class holds the game where the game loop occurs 
*               setup game mechanics such has inital value of the player and health, among other variables
*   
*/

#ifndef GAME_H
#define GAME_H

#include <raylib-cpp.hpp>
#include "math.h"
#include "player.hpp"
#include "enemy.hpp"
#include "constants.hpp"

class Game
{
private:
    Player player;
    Enemy enemies[MAX_ENEMIES];

public:
    Game();
    ~Game();
    void startGame();
    void updateGame();
    void drawGame();
};

#endif