#include "Wronganimal.hpp"
Wronganimal::Wronganimal()
{
    // this->type = 0;
}

Wronganimal::~Wronganimal()
{
    std::cout << "Wronganimal destructor activated" << std::endl;
}

void    Wronganimal::makesound(void) const
{
    std::cout << "From Wronganimal class" << std::endl;
}

std::string Wronganimal::gettype() const
{
    return (type);
}