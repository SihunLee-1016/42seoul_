#include "newZombie.hpp"

void    new_Zombie::announce(void)
{
    std::cout << *(this->name) << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

new_Zombie* new_Zombie::newZombie( std::string str)
{

    int len = str.size();
    name = new std::string(str);
}

void new_Zombie::randomChump( std::string str )
{
    int len = str.size();
    name = new std::string(str);
    this->announce();
}
