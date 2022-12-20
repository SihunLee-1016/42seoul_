#include "C.hpp"

C::~C()
{
  std::cout << "destructor of class C " << std::endl;  
}

void  C::announce()
{
  std::cout << "This is C" << std::endl;
}