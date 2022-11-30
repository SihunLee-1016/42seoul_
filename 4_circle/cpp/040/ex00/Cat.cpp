#include "Cat.hpp"
Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructor activated" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor activated" << std::endl;
}

void    Cat::makesound(void) const
{
    std::cout << "Meow" << std::endl;
}

std::string    Cat::gettype() const
{
    return(this->type);   
}