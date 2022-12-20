#include "B.hpp"

B::~B()
{
  std::cout << "destructor of class B " << std::endl;  
}

void  B::announce()
{
  std::cout << "This is B" << std::endl;
}