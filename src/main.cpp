/**
*   @brief      main class, the holder of all elements in the game
*               loads in raylib library and begins game
*   
*/

#include <raylib-cpp.hpp>
#include "game.hpp"

/**
*   @brief      main function, allows game to be setup and run on load
*               name, and game object are created here
*/
int main()
{
    raylib::Color textColor(LIGHTGRAY);
    raylib::Window gameWindow(SCREEN_W, SCREEN_H, "Ultra Super Space Rocks");
    SetTargetFPS(60);

    Game game;
    game.startGame();
    while (!gameWindow.ShouldClose())
    {
        game.updateGame();
    }

    gameWindow.Close(); //end game

    return 0;
}
