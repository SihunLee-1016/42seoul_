#include "Weapon.hpp"
Weapon::Weapon(std::string weapon_name)
{
    weapon = weapon_name;
}

std::string Weapon::getType(void)
{
	return(this->weapon);
}

void    Weapon::setType(std::string weapon_name)
{
	this->weapon = weapon_name;
}

