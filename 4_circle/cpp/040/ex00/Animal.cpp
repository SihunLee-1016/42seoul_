#include "Animal.hpp"
Animal::Animal(/* args */)
{
    this->type = 0;
}

Animal::~Animal()
{
}

virtual void    Animal::makesound(void)
{
    std::cout << "From Animal class" << std::endl;
}

std::string Animal::gettype()
{
    return (this->type);
}