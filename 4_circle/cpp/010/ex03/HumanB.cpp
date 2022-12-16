#include "HumanB.hpp"
HumanB::HumanB(std::string name)
{
	_name = name;
}

void    HumanB::attack(void)
{
	std::cout << _name << " attacks with his " << this->B_w->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon *w_type)
{
	B_w = w_type;
}