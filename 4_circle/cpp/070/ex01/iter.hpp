#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void _print(T *addr, unsigned int len) {
    unsigned int i;

    for (i = 0; i < len; i++) {
			std::cout << "idx : " << i << " value : " << addr[i] << std::endl; 
    }
}

template <typename T>
void iter(T *arr, unsigned int len, void (*f)(T *addr, unsigned int len)) {
	(void)len;
	f(arr, len);
}

#endif
