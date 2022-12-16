#include "Zombie.hpp"

Zombie::Zombie(std::string str)
{
    this->name = str;
}

Zombie::~Zombie()
{
    std::cout << this->name << "  Destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie( std::string str)
{
    Zombie *ret = new Zombie(str);
    std::cout << str << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
    return (ret);
}

