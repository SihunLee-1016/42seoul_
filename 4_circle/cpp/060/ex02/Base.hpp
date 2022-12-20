#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
class Base
{
  public:
    Base();
    virtual ~Base();
    virtual void announce();
};

#endif