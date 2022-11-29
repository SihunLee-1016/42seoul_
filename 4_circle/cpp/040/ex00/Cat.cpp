#include "Cat.hpp"
Cat::Cat()
{
    std::cout << "Cat constructor activated" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor activated" << std::endl;
}

void    Cat::makesound(void)
{
    std::cout << "Meow" << std::endl;
}
void    virtual std::string    Cat::gettype()
{
    return(this->type);   
}