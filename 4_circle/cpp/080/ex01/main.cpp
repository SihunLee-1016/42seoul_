#include "Span.hpp"
int main()
{
  Span sp = Span(5);
  Span sp2(200);

  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  
  sp2.make_num();

  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  
  std::cout << "" << std::endl;
  std::cout << "" << std::endl;
  std::cout << sp2.shortestSpan() << std::endl;
  std::cout << sp2.longestSpan() << std::endl;
  
  return 0;
}