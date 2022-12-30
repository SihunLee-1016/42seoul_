#include "easyfind.hpp"

int main()
{
  std::vector<int> vec;

  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(50);
  vec.push_back(60);

  easyfind(vec, 30);
}