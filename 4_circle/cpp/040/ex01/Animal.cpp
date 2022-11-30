#include "Animal.hpp"
Animal::Animal()
{
    // this->type = 0;
}

Animal::~Animal()
{
    std::cout << "Animal destructor activated" << std::endl;
}

void    Animal::makesound(void) const
{
    std::cout << "From Animal class" << std::endl;
}

std::string Animal::gettype() const
{
    return (type);
}