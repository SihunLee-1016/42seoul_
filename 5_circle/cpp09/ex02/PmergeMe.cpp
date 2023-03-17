#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}


PmergeMe::~PmergeMe(void) {}
void    PmergeMe::print_before_data()
{
    int i = 0;

    std::vector<int>::iterator iter;
    std::cout << "Before : ";
    for(iter = _vector.begin(); iter != _vector.end(); iter++, ++i){
        std::cout << *iter << " " ;
        if (i == 9)
        {
            std::cout << "...";
        }
    }
    std::cout << std::endl;
}

void    PmergeMe::print_after_data()
{
    std::set<int>::iterator iter;
    std::cout << "After  : ";
    for(iter = _set.begin(); iter != _set.end(); iter++){
        std::cout << *iter << " " ;
    }
    std::cout << std::endl;
}

void    PmergeMe::check_data(int argc, char** argv)
{
    int val;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == NULL)
            break;
        unsigned long ul_value = strtoul(argv[i], NULL, 10);
        if (ul_value > INT_MAX || (ul_value == 0 && argv[i][1] != ' ')) {
            std::cout << "ERROR: Out of Range" << std::endl;
            return ;
        } else
        {
            val = static_cast<int>(ul_value);
            _vector.push_back(val);
            _deque.push_back(val);
            _set.insert(val);
        }
    }
}
