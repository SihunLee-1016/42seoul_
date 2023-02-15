#include "Span.hpp"

Span::Span(unsigned int N) : max_noe(N), now_noe(0)
{
}

Span::Span(const Span& src){
  max_noe = src.max_noe;
  now_noe = src.now_noe;  
}

Span& Span::operator=(Span const& rhs){
  max_noe = rhs.max_noe;
  now_noe = rhs.now_noe;
  return *this;
}

Span::~Span(void)
{
}

const char * Span::NumberofElementOver::what() const throw() {
  return "number of element over.";
}

const char * Span::CanNotCheckSpan::what() const throw(){
  return "now noe is under 1 so Can not Check Span.";
}


void  Span::addNumber(int num)
{
  try {
    if (max_noe > now_noe) {
      vec.push_back(num);
      now_noe++;
    }
    else
      throw NumberofElementOver();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

int   Span::shortestSpan()
{
  std::vector<int> value_vec;

  try {
    if(now_noe <= 1)
      throw CanNotCheckSpan();
    for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
      for(std::vector<int>::iterator iter2 = iter + 1; iter2 != vec.end(); ++iter2) {
        if (*iter - *iter2 < 0)
          value_vec.push_back(-(*iter - *iter2));
        else
          value_vec.push_back(*iter - *iter2);
      }
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (*std::min_element(value_vec.begin(), value_vec.end()));
}

int   Span::longestSpan()
{
  std::vector<int> value_vec;

  try{
    if (now_noe <= 1)
      throw CanNotCheckSpan();
    for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
      for(std::vector<int>::iterator iter2 = iter + 1; iter2 != vec.end(); ++iter2) {
        if (*iter - *iter2 < 0)
          value_vec.push_back(-(*iter - *iter2));
        else
          value_vec.push_back(*iter - *iter2);
      }
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return (*std::max_element(value_vec.begin(), value_vec.end()));
}

void  Span::print(){ 
  for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    std::cout << *iter << std::endl;
}

void  Span::make_num() {
  int r_num;

  srand(time(NULL));
  for (unsigned int i = 0; i < max_noe; i++) {
    r_num = rand();
    addNumber(r_num);
  }
}
