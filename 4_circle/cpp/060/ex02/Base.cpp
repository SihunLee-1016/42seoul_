#include "Base.hpp"

Base::Base()
{
  std::cout << "constructor of Base" << std::endl;
}


Base::~Base()
{
  std::cout << "destructor of Base" << std::endl;
}

void  Base::announce()
{
  std::cout << "This is Base class" << std::endl;
}