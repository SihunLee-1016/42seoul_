#ifndef A_HPP
# define A_HPP
#include "Base.hpp"

class A : public Base
{
  private:
    std::string str;
  public:
    ~A();
    void  announce();
};

#endif