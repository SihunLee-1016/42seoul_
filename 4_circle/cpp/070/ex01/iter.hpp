#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void _print(T const &addr) {
    std::cout << " value : " << addr << std::endl; 
}

template <typename T>
void iter(T *arr, unsigned int len, void (*f)(T const &addr)) {
	for(unsigned int i = 0; i < len; i++){
        f(*arr);
        arr++;
    }
}

#endif
