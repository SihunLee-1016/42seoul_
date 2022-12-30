#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>
class Span
{
  private:
    unsigned int  max_noe;
    std::vector<int> vec;
  public:
    Span(void);
    Span(unsigned int N);
    Span(const Span& src);
    ~Span(void);
    Span& operator=(Span const& rhs);

};

#endif