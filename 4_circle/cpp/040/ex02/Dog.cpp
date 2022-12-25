#include "Dog.hpp"
Dog::Dog() : _brain(NULL)
{
    this->type = "Dog";
    _brain = new Brain();
    std::cout << "Dog constructor activated" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor activated" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &obj) : _brain(NULL)
{
    std::cout << "Dog constructor2 activated" << std::endl;
    type = obj.gettype();
    _brain = new Brain(*obj.getBrain());
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog operator activated" << std::endl;
    type = obj.gettype();
    *_brain = *obj.getBrain();
    return *this;
}

void    Dog::makesound(void) const
{
    std::cout << "Bark" << std::endl;
}

std::string    Dog::gettype() const
{
    return(this->type);   
}

Brain* Dog::getBrain() const
{
    if (_brain)
        return _brain;
    else
        return NULL;
}