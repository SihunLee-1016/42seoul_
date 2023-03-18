#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2)
        return 1;

    PmergeMe pm;

    pm.check_data(argc, argv);
    pm.print_before_data();
    pm.print_after_data();
    pm.sort_vector();
    pm.sort_deque();
    return 0;
}