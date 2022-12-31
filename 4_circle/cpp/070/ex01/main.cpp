#include "iter.hpp"

int main()
{
    int i_arr[5] = {1,2,3,4,5};
    char c_arr[5] ={'a','b','c','d','e'};
    std::string s_arr[5] = {"this", "is", "si", "hun", "lee"};

    ::iter(i_arr, sizeof(i_arr) / sizeof(*i_arr), _print);
    std::cout << std::endl;
    ::iter(c_arr, sizeof(c_arr) / sizeof(*c_arr), _print);
    std::cout << std::endl;
    ::iter(s_arr, sizeof(s_arr) / sizeof(*s_arr), _print);
}