#ifndef PLAYER_H
#define PLAYER_H

#include <raylib-cpp.hpp>
#include "constants.hpp"

class Player
{
private:
    raylib::Vector2 position;
    raylib::Vector2 velocity;
    float direction;
    float accel;
    raylib::Vector3 collide;
    float height;
    int health;

public:
    Player();
    ~Player();
    raylib::Vector2 getPosition();
    void setPosition(raylib::Vector2 newPos);
    raylib::Vector2 getVelocity();
    void setVelocity(raylib::Vector2 newVel);
    float getDirection();
    void setDirection(float newDir);
    float getAcceleration();
    void setAcceleration(float newAcc);
    raylib::Vector3 getCollide();
    void setCollide(raylib::Vector3 newCol);
    float getHeight();
    void setHeight(float newH);
    int getHealth();
    void setHealth(int modifier);
    void move();
};

#endif