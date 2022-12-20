#include "A.hpp"

A::~A()
{
  std::cout << "destructor of class A " << std::endl;
}

void  A::announce()
{
  std::cout << "This is A" << std::endl;
}