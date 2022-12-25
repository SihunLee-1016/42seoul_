#include "Wrongcat.hpp"
Wrongcat::Wrongcat()
{
    this->type = "Wrong cat";
    std::cout << "Wrongcat constructor activated" << std::endl;
}

Wrongcat::~Wrongcat()
{
    std::cout << "Wrongcat destructor activated" << std::endl;
}

Wrongcat::Wrongcat(const Wrongcat &obj)
{
    this->type = obj.gettype();
    std::cout << "Wrongcat copy constructor activated" << std::endl;
}

Wrongcat& Wrongcat::operator=(const Wrongcat &obj)
{
    this->type = obj.gettype();
    std::cout << "Wrongcat operator activated" << std::endl;
    return *this;
}

void    Wrongcat::makesound(void) const
{
    std::cout << "WC : Bark Bark" << std::endl;
}

std::string    Wrongcat::gettype() const
{
    return(this->type);   
}