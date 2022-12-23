#include "iter.hpp"

int main()
{
    int i_arr[5] = {1,2,3,4,5};

    ::iter(i_arr, sizeof(i_arr) / sizeof(*i_arr), _print);
}