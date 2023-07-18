/**
*   @brief      The weapon class is made to be extended into various melee and ranged weapons 
*               it is in charge of holding the weapons properties : name, damage, ammunition and frequency
*               
*   @author Josh O'Neil
*   @date   2023-03-14
*   
*/
#include "weapon.hpp"

/**
* @brief    The Weapon Constructor creates a generic weapon
*   @param name The name of the weapon
*   @param damage The damage the weapon inflicts minimum 1
*   @param maxAmmo if set to 0 or negative integer infinite ammo is assumed
*   @param frequency the frequency of the weapon's attack minimum 0
*/
Weapon::Weapon(std::string name, int damage, int maxAmmo, int freqency){
    this->name = name;
    if(damage > 0) //check 
        this->damage = damage;
    
    if(maxAmmo > 0) //check for infinite ammo
        this->ammo = Ammo(maxAmmo);
    else
        this->ammo = Ammo();
    
    if(frequency >= 0 )
        this->frequency = frequency;
}

/**
 * @brief
*/
Weapon::~Weapon(){

}

/**
 * @brief Allows one to check if a weapon is on cooldown
 * @return returns the true if the weapon is on cooldown and false otherwise
*/
bool Weapon::checkCoolDown(){
    return freqCoolDown;
}

/**
 * @brief Allows one to add ammunition to the weapon
 * @param ammount the ammount of ammunition that is attempted to be added
*/
void Weapon::addAmmo(int ammount){
    ammo.add(ammount);
}

/**
 * @brief Allows one to decrease ammunition in the weapon
 * @param ammount the ammount of ammunition that is attempted to be lost
*/
void Weapon::decreaseAmmo(int ammount){
    ammo.lose(ammount);
}

/**
 * @brief This makes the weapon attack decreasing ammo and frequency appropriately
 * @param direction the direction the attack is headed in
*/
void Weapon::attack(int direction){
    // todo what should a default weapon attack do? Should it shoot a laser? Create a melee swipe? Just colide with whatever is in front of it?
}