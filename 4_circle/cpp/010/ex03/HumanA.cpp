#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type)
{
    _name = name;
    _weapon_type = type.getType();
}

void    HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << _weapon_type << std::endl;
}
