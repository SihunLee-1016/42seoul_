#include "Cat.hpp"
Cat::Cat() : _brain(NULL)
{
    this->type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor activated" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor activated" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat &obj) : _brain(NULL)
{
    std::cout << "Cat constructor2 activated" << std::endl;
    type = obj.gettype();
    _brain = new Brain(*obj.get_brain());
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat operator activated" << std::endl;
    type = obj.gettype();
    *_brain = *obj.get_brain();
    return *this;
}

void    Cat::makesound() const
{
    std::cout << "Meow" << std::endl;
}

void    Cat::check_brain()
{
    for(int i = 0; i < 100; i++)
        std::cout << this->_brain->getIdea(i) << " ";
    std::cout << std::endl;
}

std::string    Cat::gettype() const
{
    return(this->type);   
}

Brain* Cat::get_brain() const
{
    if (_brain)
        return _brain;
    else
        return NULL;
}