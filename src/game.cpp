/**
*   @brief      game class holds the game where the game loop occurs 
*               setup game mechanics such has inital value of the player and health, among other variables
*   
*/
#include "game.hpp"

/**
*   @brief      Game constructor, constructs game object
*   
*/
Game::Game(){};

/**
*   @brief      Game deconstructor, deconstructs game object
*   
*/
Game::~Game(){};

/**
*   @brief      Start game method, allows game processes to load in and begin with their inital values, call enemies as well
*               set player, enemy default positions
*   
*/
void Game::startGame()
{
    float initHeight = (PLAYER_SIZE / 2) / tanf(20 * DEG2RAD); // calculate initial player values
    raylib::Vector2 initPos = (raylib::Vector2){SCREEN_W / 2, SCREEN_H / 2 - initHeight / 2};
    raylib::Vector2 initVel = (raylib::Vector2){0.0f, 0.0f};
    raylib::Vector3 initCol = (raylib::Vector3){initPos.x + sin(0 * DEG2RAD) * (initHeight / 2.5f), initPos.y - cos(0 * DEG2RAD) * (initHeight / 2.5f), 12};

    Player newPlayer; // initialize player
    this->player = newPlayer;
    this->player.setPosition(initPos); // set initial player object values
    this->player.setVelocity(initVel);
    this->player.setDirection(0.0f);
    this->player.setAcceleration(0.0f);
    this->player.setCollide(initCol);
    this->player.setHeight(initHeight);
    this->player.setHealth(100);

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        int posX = GetRandomValue(0, SCREEN_W); // calculate random X position for enemy
        while ((posX > SCREEN_W / 2 - 150) && (posX < SCREEN_W / 2 + 150))
        { // calculate until correct range
            posX = GetRandomValue(0, SCREEN_W);
        }

        int posY = GetRandomValue(0, SCREEN_H); // calculate random Y position for enemy
        while ((posY > SCREEN_H / 2 - 150) && (posY < SCREEN_H / 2 + 150))
        { // calculate until correct range
            posY = GetRandomValue(0, SCREEN_H);
        }

        int velX = GetRandomValue(-ENEMY_SPEED, ENEMY_SPEED); // calculate random velocity for enemy
        int velY = GetRandomValue(-ENEMY_SPEED, ENEMY_SPEED);
        while (velX == 0 && velY == 0)
        { // calculate until correct range
            int velX = GetRandomValue(-ENEMY_SPEED, ENEMY_SPEED);
            int velY = GetRandomValue(-ENEMY_SPEED, ENEMY_SPEED);
        }

        Enemy enemy; // initialize enemy object with values
        enemy.setPosition((raylib::Vector2){(float)posX, (float)posY});
        enemy.setVelocity((raylib::Vector2){(float)velX, (float)velY});
        this->enemies[i] = enemy; // add to enemy list
    }
};

/**
*   @brief      update game loops through game frames to allow for movement to occur and updates to be processed
*               based on player health, if player is dead then game loop breaks
*   
*/
void Game::updateGame()
{
    if (this->player.getHealth() > 0) // if player is alive
    {
        this->player.move(); // move player position
        for (int i = 0; i < MAX_ENEMIES; i++)
        { // move alive enemy positions
            if (this->enemies[i].getHealth() > 0)
            {
                this->enemies[i].move();
            }
        };

        raylib::Vector3 newCol = (raylib::Vector3){this->player.getPosition().x + sin(this->player.getDirection() * DEG2RAD) * (this->player.getHeight() / 2.5f), this->player.getPosition().y - cos(this->player.getDirection() * DEG2RAD) * (this->player.getHeight() / 2.5f), 12};
        this->player.setCollide(newCol); // calculate new collide value for player
        for (int i = 0; i < MAX_ENEMIES; i++)
        { // check for collisions between player and enemies
            if (this->enemies[i].getHealth() > 0)
            {
                if (CheckCollisionCircles((raylib::Vector2){this->player.getCollide().x, this->player.getCollide().y}, this->player.getCollide().z, this->enemies[i].getPosition(), this->enemies[i].getRadius()))
                { // collision -> kill player (for now)
                    this->player.setHealth(-100);
                };
            };
        };
    }
    else
    { // player dead -> restart the game using space or enter key
        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER))
        {
            startGame();
        }
    }

    drawGame(); //redraw game
}

/**
*   @brief      Draws visual objects on the game board
*   
*/
void Game::drawGame()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    if (this->player.getHealth() > 0)
    { // if player is alive, draw game
        raylib::Vector2 vector1 = {this->player.getPosition().x + sinf(this->player.getDirection() * DEG2RAD) * this->player.getHeight(), this->player.getPosition().y - cosf(this->player.getDirection() * DEG2RAD) * this->player.getHeight()};
        raylib::Vector2 vector2 = {this->player.getPosition().x - cosf(this->player.getDirection() * DEG2RAD) * (PLAYER_SIZE / 2), this->player.getPosition().y - sinf(this->player.getDirection() * DEG2RAD) * (PLAYER_SIZE / 2)};
        raylib::Vector2 vector3 = {this->player.getPosition().x + cosf(this->player.getDirection() * DEG2RAD) * (PLAYER_SIZE / 2), this->player.getPosition().y + sinf(this->player.getDirection() * DEG2RAD) * (PLAYER_SIZE / 2)};
        DrawTriangle(vector1, vector2, vector3, MAROON); // draw player object

        for (int i = 0; i < MAX_ENEMIES; i++)
        { // draw all enemies
            if (this->enemies[i].getHealth() > 0)
            {
                DrawCircleV(this->enemies[i].getPosition(), this->enemies[i].getRadius(), BLACK);
            }
            else
            {
                DrawCircleV(this->enemies[i].getPosition(), this->enemies[i].getRadius(), Fade(LIGHTGRAY, 0.3f));
            }
        };
    }
    else
    { // player dead -> show instructions to restart game
        DrawText("Press [SPACE] or [ENTER] to restart the game.", SCREEN_W / 2 - MeasureText("Press [SPACE] or [ENTER] to restart the game.", 18) / 2, SCREEN_H / 2 - 50, 20, DARKGRAY);
    }

    EndDrawing();
}
