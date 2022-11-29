#include "Dog.hpp"
Dog::Dog()
{
    std::cout << "Dog constructor activated" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog constructor2 activated" << std::endl;
}

Dog& operator=(const Dog &obj)
{
    std::cout << "Dog operator activated" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor activated" << std::endl;
}

void    Dog::makesound(void)
{
    std::cout << "Bark" << std::endl;   
}

void    virtual std::string    Dog::gettype()
{
    return(this->type);
}