#include "Wronganimal.hpp"
Wronganimal::Wronganimal()
{
    this->type = "Wrong animal";
}

Wronganimal::~Wronganimal()
{
    std::cout << "Wronganimal destructor activated" << std::endl;
}

Wronganimal::Wronganimal(const Wronganimal &obj)
{
    this->type = obj.gettype();
    std::cout << "Wronganimal copy constructor activated" << std::endl;
}

Wronganimal& Wronganimal::operator=(const Wronganimal &obj)
{
    this->type = obj.gettype();
    std::cout << "Wronganimal operator activated" << std::endl;
    return *this;
}

void    Wronganimal::makesound(void) const
{
    std::cout << "From Wronganimal class" << std::endl;
}

std::string Wronganimal::gettype() const
{
    return (type);
}