#include "Dog.hpp"
#include "Brain.hpp"
Dog::Dog()
{
    this->type = "Dog";
    this->dog_brain = new Brain();
    std::cout << "Dog constructor activated" << std::endl;
}

/*Dog::Dog(const Dog &obj)
{
    std::cout << "Dog constructor2 activated" << std::endl;
}

Dog& operator=(const Dog &obj)
{
    std::cout << "Dog operator activated" << std::endl;
}*/

Dog::~Dog()
{
    std::cout << "Dog destructor activated" << std::endl;
    delete this->dog_brain;
}

void    Dog::makesound(void) const
{
    std::cout << "Bark" << std::endl;   
}

std::string Dog::gettype() const 
{
    return(this->type);
}