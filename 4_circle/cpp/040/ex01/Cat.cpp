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

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat constructor2 activated" << std::endl;
    type = obj.gettype();
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat operator activated" << std::endl;
    this->type = obj.gettype();
    return *this;
}

void    Cat::makesound(void) const
{
    std::cout << "Meow" << std::endl;
}

std::string    Cat::gettype() const
{
    return(this->type);   
}