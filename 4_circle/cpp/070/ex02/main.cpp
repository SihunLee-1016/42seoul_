// #include "Array.hpp"

// int main(void) {
//   Array<std::string> arr1(3);
  
//   arr1[0] = "42";
//   arr1[1] = "Seoul";
//   arr1[2] = "silee";
  
//   Array<std::string> arr2(arr1);

//   for (std::size_t i = 0 ; i < arr1.getsize() ; ++i)
//     std::cout << arr1[i] << " ";
//   std::cout << std::endl;

//   for (std::size_t i = 0 ; i < arr1.getsize() ; ++i)
//     std::cout << arr2[i] << " ";
//   std::cout << std::endl;
  
//   try {
//     arr1[3] = "Not Work";
//     arr2[3] = "Not Reach";
//   } catch (std::exception& e) {
//     std::cout << e.what() << std::endl;
//   }
//   std::cout << "-----------------------------------" << std::endl;
//   return 0;
// }
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++){
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}