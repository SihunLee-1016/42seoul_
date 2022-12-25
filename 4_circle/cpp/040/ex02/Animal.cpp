#include "Animal.hpp"
Animal::Animal() : type("animal"){
}

Animal::Animal(const Animal &obj) : type(obj.gettype()) {
}

Animal& Animal::operator=(const Animal &obj)
{
    type = obj.gettype();
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor activated" << std::endl;
}

std::string Animal::gettype() const
{
    return (type);
}