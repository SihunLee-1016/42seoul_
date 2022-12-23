#include "Array.hpp"

int main(void)
{
    Array<int> a(3);
    
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    Array<int> b(a);
    std::cout << a[0] << a[1] << a[2]  <<std::endl;
    // std::cout << b[0] << b[1] << b[2] <<std::endl;
   
    // Array<char> c(4);
}