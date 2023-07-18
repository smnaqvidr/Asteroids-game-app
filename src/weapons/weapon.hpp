/**
 *   @brief      Header File of the weapon class
 *   @author     Josh O'Neil
 *   @date       2023-03-14
 */

#ifndef WEAPON_H
#define WEAPON_H

#include <raylib-cpp.hpp>
#include "../constants.hpp"
#include "ammo.hpp"
#include <string>

class Weapon
{
private:
    std::string name;
    int damage = 1;
    int frequency = 0;
    Ammo ammo;
    bool freqCoolDown;

public:
    Weapon(std::string name, int damage, int maxAmmo, int freqency); // set maxAmmo to 0 or negative for infinite ammo
    ~Weapon();
    bool checkCoolDown();
    void addAmmo(int ammount);
    void decreaseAmmo(int ammount);
    void attack(int direction);
};

#endif