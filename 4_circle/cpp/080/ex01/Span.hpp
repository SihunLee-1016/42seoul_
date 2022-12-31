#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>
#include <exception>
#include <sys/wait.h>

class Span
{
  private:
    unsigned int  max_noe;
    unsigned int  now_noe;
    std::vector<int> vec;
  public:
    
    class NumberofElementOver : public std::exception {
      const char * what() const throw();
    };

    class CanNotCheckSpan : public std::exception {
      const char * what() const throw();
    };

    Span(const Span& src);
    Span& operator=(Span const& rhs);
    Span(unsigned int N);
    ~Span(void);
    void  addNumber(int num);
    int   shortestSpan();
    int   longestSpan();
    void  print();
};

template <typename T>
void  print_vec(T vec) {
  for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    std::cout << *iter << std::endl;
}

#endif