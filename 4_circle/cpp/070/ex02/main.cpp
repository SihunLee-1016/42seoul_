#include "Array.hpp"

int main(void) {
  Array<std::string> arr1(3);
  
  arr1[0] = "42";
  arr1[1] = "Seoul";
  arr1[2] = "silee";
  
  Array<std::string> arr2(arr1);

  for (std::size_t i = 0 ; i < arr1.getsize() ; ++i)
    std::cout << arr1[i] << " ";
  std::cout << std::endl;

  for (std::size_t i = 0 ; i < arr1.getsize() ; ++i)
    std::cout << arr2[i] << " ";
  std::cout << std::endl;
  
  try {
    arr1[3] = "Not Work";
    arr2[3] = "Not Reach";
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "-----------------------------------" << std::endl;
  return 0;
}