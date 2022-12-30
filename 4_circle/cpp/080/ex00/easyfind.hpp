#include <iostream>
#include <vector>

template <typename T>
void  easyfind(T vec, int num) {
  for(std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter) {
    if (num == *iter) {
      std::cout << "value found" << std::endl;
      return ;
    }
  }
  
}