#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << *(this->name) << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::makeZombie( std::string str)
{
    int len = str.size();
    name = new std::string(str);
}

void Zombie::randomChump( std::string str )
{
    int len = str.size();
    name = new std::string(str);
    this->announce();
}

