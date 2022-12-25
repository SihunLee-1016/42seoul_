#include "Dog.hpp"
Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog constructor activated" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog constructor2 activated" << std::endl;
    type = obj.gettype();
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog operator activated" << std::endl;
    this->type = obj.gettype();
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor activated" << std::endl;
}

void    Dog::makesound(void) const
{
    std::cout << "Bark" << std::endl;   
}

std::string Dog::gettype() const 
{
    return(this->type);
}