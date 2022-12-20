#ifndef B_HPP
# define B_HPP
#include "Base.hpp"

class B : public Base
{
  private:
    std::string str;
  public:
    ~B();
    void  announce();
};

#endif