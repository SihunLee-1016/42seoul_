#include "HumanB.hpp"
HumanB::HumanB(std::string name)
{
	_name = name;
}

void    HumanB::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon_type << std::endl;
}

void    HumanB::setWeapon(Weapon w_type)
{
	_weapon_type = w_type.getType();
}