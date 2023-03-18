#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const& tmp) { (void)tmp; }
PmergeMe& PmergeMe::operator=(PmergeMe const& tmp) { (void)tmp; }

void PmergeMe::print_after_data() {
  std::set<int>::iterator iter;
  std::cout << "After  : ";
  for (iter = _set.begin(); iter != _set.end(); iter++) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
}
void PmergeMe::print_before_data() {
  int i = 0;

  std::vector<int>::iterator iter;
  std::cout << "Before : ";
  for (iter = _vector.begin(); iter != _vector.end(); iter++, ++i) {
    std::cout << *iter << " ";
    if (i == 9) {
      std::cout << "...";
    }
  }
  std::cout << std::endl;
}

void PmergeMe::check_data(int argc, char** argv) {
  int val;

  for (int i = 1; i < argc; i++) {
    if (argv[i] == NULL) break;
    unsigned long ul_value = strtoul(argv[i], NULL, 10);
    if (ul_value > INT_MAX || (ul_value == 0 && argv[i][1] != ' ')) {
      std::cout << "ERROR: Out of Range" << std::endl;
      return;
    } else {
      val = static_cast<int>(ul_value);
      _vector.push_back(val);
      _deque.push_back(val);
      _set.insert(val);
    }
  }
}

void PmergeMe::sort_vector() {
  timespec start;
  timespec end;
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  mi_sort(_vector, 0, _vector.size() - 1);
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double runSec = end.tv_sec - start.tv_sec;
  double runNSec = end.tv_nsec - start.tv_nsec;
  double sortTime = (runSec * 1000000L) + (runNSec / 1000);
  std::cout << "Time to process a range of " << _set.size()
            << " elements with std::"
            << "vecor"
            << " : " << sortTime << " us" << std::endl;
}

void PmergeMe::sort_deque() {
  timespec start;
  timespec end;
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  mi_sort(_deque, 0, _deque.size() - 1);
  ::clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  double runSec = end.tv_sec - start.tv_sec;
  double runNSec = end.tv_nsec - start.tv_nsec;
  double sortTime = (runSec * 1000000L) + (runNSec / 1000);
  std::cout << "Time to process a range of " << _set.size()
            << " elements with std::"
            << "vecor"
            << " : " << sortTime << " us" << std::endl;
}
