#ifndef C_HPP
# define C_HPP
#include "Base.hpp"

class C : public Base
{
  private:
    std::string str;
  public:
    ~C();
    void  announce();
};

#endif