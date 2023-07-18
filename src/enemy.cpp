/**
*   @brief      Enemy class holds the object class for the enemy
*               has movement, health, position, and size of enemy
*                enemy can move around like player
*   
*/
#include "enemy.hpp"

/**
* @brief    Create enemy using constructor
*           set defualt value of the enemy
*/

Enemy::Enemy()
{
    this->position = (raylib::Vector2){0, 0};
    this->velocity = (raylib::Vector2){0, 0};
    this->radius = 35.0f;
    this->health = 100;
}

/**
* @brief    destroy enemy using deconstructor
*/
Enemy::~Enemy()
{
}

/**
* @brief    Get x y coordinates of the enemy
* @return   vector2 of the enemy where first element is x, second is y
*/
raylib::Vector2 Enemy::getPosition()
{
    return this->position;
};

/**
* @brief    Set x y coordinates of the enemy
* @param   vector2 of the enemy where first element is x, second is y, set it to position of the enmeny 
*/
void Enemy::setPosition(raylib::Vector2 newPos)
{
    this->position = newPos;
};

raylib::Vector2 Enemy::getVelocity()
{
    return this->velocity;
};

/**
* @brief    Set velocity coordinates of the enemy
* @param   vector2 velocity of the enemy in vector 2 form 
*/
void Enemy::setVelocity(raylib::Vector2 newVel)
{
    this->velocity = newVel;
};

/**
* @brief    Get radius of the enemy
* @return   float of the radius of enenmy 
*/
float Enemy::getRadius()
{
    return this->radius;
};

/**
* @brief    Set radius of the enemy
* @param   float of the radius of enenmy 
*/
void Enemy::setRadius(float newRad)
{
    this->radius = newRad;
};

/**
* @brief    Get health of the enemy
* @return   int of the health of enenmy 
*/
int Enemy::getHealth()
{
    return this->health;
};

/**
* @brief    set health of the enemy
* @param   int of the health of enenmy 
*/
void Enemy::setHealth(int modifier)
{
    this->health += modifier;
};

/**
* @brief    Move the enemy coordinates based on the current velocity, do wall collison if needed
*/
void Enemy::move()
{
    this->position.x += this->velocity.x; // new position based on velocity (with rotation)
    this->position.y += this->velocity.y;

    if (this->position.x > SCREEN_W + this->radius)
    { // enemy is moving out of screen width -> move to other side
        this->position.x = -(this->radius);
    }
    else if (this->position.x < 0 - this->radius)
    {
        this->position.x = SCREEN_W + this->radius;
    }

    if (this->position.y > SCREEN_H + this->radius)
    { // enemy is moving out of screen height -> move to other side
        this->position.y = -(this->radius);
    }
    else if (this->position.y < 0 - this->radius)
    {
        this->position.y = SCREEN_H + this->radius;
    }
};