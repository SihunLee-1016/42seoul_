#include "HumanA.hpp"
HumanA::HumanA(std::string name, Weapon& type) : A_w(type)
{
    _name = name;
}

void    HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << A_w.getType() << std::endl;
}
