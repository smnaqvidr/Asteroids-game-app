/**
*   @brief      Header File of the Ammo class
*   @author     Josh O'Neil
*   @date       2023-03-14
*/

#ifndef AMMO_H
#define AMMO_H


class Ammo
{
private:
    int maxAmmo, curAmmo = -1;
    bool isInfinite = false;

public:
    Ammo(int maxAmmo);
    Ammo(); //Used for infinite Ammo
    bool use();
    void add(int ammount);
    int lose(int ammount);
    int getAmmo();
    int getMax();
};

#endif