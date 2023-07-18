/**
*   @brief      Directive Enemy class holds the object class for the enemy 
*               has movement, health, position, and size of enemy
*                enemy can move around like player
*   
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <raylib-cpp.hpp>
#include "constants.hpp"

class Enemy
{
private:
    raylib::Vector2 position;
    raylib::Vector2 velocity;
    float radius;
    int health;

public:
    Enemy();
    ~Enemy();
    raylib::Vector2 getPosition();
    void setPosition(raylib::Vector2 newPos);
    raylib::Vector2 getVelocity();
    void setVelocity(raylib::Vector2 newVel);
    float getRadius();
    void setRadius(float newRad);
    int getHealth();
    void setHealth(int modifier);
    void move();
};

#endif