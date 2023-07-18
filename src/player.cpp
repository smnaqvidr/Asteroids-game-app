/**
*   @brief      player class holds the player object
*               creates the positon, velocity, direction, acceleration, collision, and health/radius of the object
*   
*/
#include "player.hpp"

/**
*   @brief      player constructor initalizes the values of all variables to their default value
*   
*/
Player::Player()
{
    this->position = (raylib::Vector2){0, 0};
    this->velocity = (raylib::Vector2){0, 0};
    this->direction = 0.0f;
    this->accel = 0.0f;
    this->collide = (raylib::Vector3){0, 0, 0};
    this->height = 0.0f;
    this->health = 100;
};

/**
*   @brief      deallocates player values
*   
*/
Player::~Player(){};

/**
*   @brief      captures players coordiates
* @return        vector2 of player's coordinates in x,y format
*   
*/
raylib::Vector2 Player::getPosition()
{
    return this->position;
};

/**
*   @brief      set players coordiates
* @param        vector2 of player's coordinates in x,y format
*   
*/
void Player::setPosition(raylib::Vector2 newPos)
{
    this->position = newPos;
};

/**
*   @brief      captures players velotcity
* @return        vector2 of player's velocity
*   
*/
raylib::Vector2 Player::getVelocity()
{
    return this->velocity;
};

/**
*   @brief      set players velotcity
* @param        vector2 of player's velocity
*   
*/
void Player::setVelocity(raylib::Vector2 newVel)
{
    this->velocity = newVel;
};

/**
*   @brief      captures players direction
* @return        float of player's direction
*   
*/
float Player::getDirection()
{
    return this->direction;
};

/**
*   @brief      sets players direction
* @param        float of player's direction
*   
*/
void Player::setDirection(float newDir)
{
    this->direction = newDir;
};

/**
*   @brief      captures players acceleration
* @return        float of player's acceleration
*   
*/
float Player::getAcceleration()
{
    return this->accel;
};

/**
*   @brief      set players acceleration
* @param        float of player's acceleration
*   
*/
void Player::setAcceleration(float newAcc)
{
    this->accel = newAcc;
};

/**
*   @brief      captures players collision
* @return        vector3 of player's collision
*   
*/
raylib::Vector3 Player::getCollide()
{
    return this->collide;
};

/**
*   @brief      set players collision
* @param        vector3 of player's collision
*   
*/
void Player::setCollide(raylib::Vector3 newCol)
{
    this->collide = newCol;
};

/**
*   @brief      captures players height
* @return        float of player's height
*   
*/
float Player::getHeight()
{
    return this->height;
};

/**
*   @brief      set players height
* @param        float of player's height
*   
*/
void Player::setHeight(float newH)
{
    this->height = newH;
};

/**
*   @brief      captures players health
* @return        int of player's health
*   
*/
int Player::getHealth()
{
    return this->health;
};

/**
*   @brief      set players health
* @param        int of player's health
*   
*/
void Player::setHealth(int modifier)
{
    this->health += modifier;
};

/**
*   @brief      move player based on keyboard input, edit if wall collision
*               speed up and slow down player if needed
*/
void Player::move()
{
    if (IsKeyDown(KEY_LEFT))
    { // left key rotation
        this->direction -= 5;
    }
    if (IsKeyDown(KEY_RIGHT))
    { // right key rotation
        this->direction += 5;
    }

    if (IsKeyDown(KEY_UP))
    { // up key acceleration
        if (this->accel < 1)
        {
            this->accel += 0.04f;
        }
    }
    else
    { // gradually decelerate if up key is not pressed
        if (this->accel <= 0)
        {
            this->accel = 0;
        }
        else
        {
            this->accel -= 0.02f;
        }
    }

    if (IsKeyDown(KEY_DOWN))
    { // down key deceleration
        if (this->accel <= 0)
        {
            this->accel = 0;
        }
        else
        {
            this->accel -= 0.04f;
        }
    }

    this->velocity.x = sin(this->direction * DEG2RAD) * PLAYER_SPEED; // update player velocity
    this->velocity.y = cos(this->direction * DEG2RAD) * PLAYER_SPEED;

    this->position.x += this->velocity.x * this->accel; // new player position based on velocity (with rotation) and acceleration
    this->position.y -= this->velocity.y * this->accel;

    if (this->position.x > SCREEN_W + this->height)
    { // player is moving out of screen width -> move to other side
        this->position.x = -(this->height);
    }
    else if (this->position.x < -(this->height))
    {
        this->position.x = SCREEN_W + this->height;
    }

    if (this->position.y > SCREEN_H + this->height)
    { // player is moving out of screen height -> move to other side
        this->position.y = -(this->height);
    }
    else if (this->position.y < -(this->height))
    {
        this->position.y = SCREEN_H + this->height;
    }
};