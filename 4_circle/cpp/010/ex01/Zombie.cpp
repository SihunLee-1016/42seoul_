#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << *(this->name) << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::makeZombie( std::string str)
{
    name = new std::string(str);
}

void Zombie::randomChump( std::string str )
{
    name = new std::string(str);
    this->announce();
}

