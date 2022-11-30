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

void    Wrongcat::makesound(void) const
{
    std::cout << "WC : Bark Bark" << std::endl;
}

std::string    Wrongcat::gettype() const
{
    return(this->type);   
}