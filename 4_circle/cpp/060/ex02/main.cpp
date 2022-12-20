#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
  srand((unsigned int)time(NULL));
  if (rand() % 3 == 0)
  {
    return (new A());
  }
  else if (rand() % 3 == 1)
  {
    return (new B());
  }
  else
  {
    return (new C());
  }
}

void identify(Base* p)
{
  if (dynamic_cast<A*>(p))
    std::cout << "pointer identifi : A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "pointer identifi : B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "pointer identifi : C" << std::endl;
  else
    std::cout <<"Failed" << std::endl;
}

void identify(Base& p)
{
  try
  {
    A &a = dynamic_cast<A&>(p);
    std::cout << "Reference identifi : A" << std::endl;
    (void)a;
  }
  catch(std::exception& e){}
  try
  {
    B &b = dynamic_cast<B&>(p);
    std::cout << "Reference identifi : B" << std::endl;
    (void)b;
  }
  catch(std::exception& e){}
  try
  {
    C &c = dynamic_cast<C&>(p);
    std::cout << "Reference identifi : C" << std::endl;
    (void)c;
  }
  catch(std::exception& e){}
  
}

int main()
{
  Base *a = generate();
  identify(a);
  identify(*a);

  delete a;
  return 0;  
}