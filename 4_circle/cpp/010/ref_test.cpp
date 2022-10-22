#include <iostream>

void    add(int &ref)
{
    ref +=1 ;
}

int main()
{
    int a = 1;
    // -> int &ref = a 꼴이므로. 레퍼런스로 사용 가능

    add(a);
    std::cout << a << std::endl;
    
    int& ref = a;
    ref = 2;
    

    std::cout << &a << std::endl;
    std::cout << &ref << std::endl;
}