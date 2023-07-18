/**
 *   @brief      Ammo class holds the ammount of ammunition a weapon has.
 *               The ammo class decreases the ammount of ammo with use() and can increase it's ammo with add()
 *   @author     Josh O'Neil
 *   @date       2023-03-14
 */
#include "ammo.hpp"

/**
 *   @brief Constructor for making ammo with finite ammount start with a full clip
 *   @param maxAmmo sets the maximum ammount of ammo for the weapon and sets the current ammount to that as well
 */
Ammo::Ammo(int maxAmmo)
{
    this->maxAmmo = maxAmmo;
    this->curAmmo = maxAmmo;
}

/**
 * @brief Constructor for making ammo with infinite ammount */
Ammo::Ammo()
{
    this->isInfinite = true;
}

/**
 *   @brief uses up some ammunition returning true if usable and false if not
 *   @return returns true if ammo was decreased and false if not enough ammo to use
 */
bool Ammo::use()
{
    if (curAmmo > 0)
    {
        curAmmo--;
        return true;
    }
    else if (isInfinite)
        return true;
    return false;
}

/**
 *   @brief adds ammuntion equal to ammount given up to max
 *   @param ammount the ammount that is added to current ammunition
 */
void Ammo::add(int ammount)
{
    curAmmo += ammount;
    if (curAmmo > maxAmmo)
        curAmmo = maxAmmo;
}

/**
 *   @brief loses ammunition equal to minimum 0 returns the ammount lost
 *   @param ammount The ammount of ammunition to be lost from current ammunition
 *   @return returns the ammount of ammunition that was lost or drop
 */
int Ammo::lose(int ammount)
{
    if (isInfinite)
        return 0;

    curAmmo -= ammount;
    if (curAmmo < 0)
    {
        ammount += curAmmo; // lower ammount by the negative cur ammo
        curAmmo = 0;
    }

    return ammount;
}

/**
 *   @brief returns current ammount of ammuntion if infinite returns -1
 *   @return integer of current ammount of ammunition -1 if infinite
 */
int Ammo::getAmmo()
{
    return curAmmo;
}

/**
 *   @brief returns max ammount of ammuntion if infinite returns -1
 *   @return integer of max ammount of ammunition -1 if infinite
 */
int Ammo::getMax()
{
    return maxAmmo;
}