#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <climits>  // for INT_MAX
#include <cstdlib>  // for strtoul()
#include <deque>
#include <iostream>
#include <set>
#include <vector>

class PmergeMe {
 private:
  std::set<int> _set;
  std::vector<int> _vector;
  std::deque<int> _deque;
  PmergeMe(PmergeMe const& tmp);
  PmergeMe& operator=(PmergeMe const& tmp);

 public:
  PmergeMe(void);
  ~PmergeMe(void);
  void check_data(int argc, char** argv);
  void print_after_data();
  void print_before_data();
  void sort_vector();
  void sort_deque();

  template <typename T>
  void insertSort(T& data, int left, int right) {
    for (int i = left; i < right; i++) {
      int tempVal = data[i + 1];
      int j = i + 1;
      while (j > left && data[j - 1] > tempVal) {
        data[j] = data[j - 1];
        j--;
      }
      data[j] = tempVal;
    }
  }

  template <typename T>
  T data_copy(T& data, int start, int end) {
    T ret;
    for (int i = start; i < end; i++) {
      ret.push_back(data[i]);
    }
    return ret;
  }

  template <typename T>
  void merge(T& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T l_a = data_copy(data, left, mid + 1);
    T r_a = data_copy(data, mid + 1, right + 1);

    int r_idx = 0;
    int l_idx = 0;
    for (int i = left; i < right - left + 1; i++) {
      if (r_idx == n2) {
        data[i] = l_a[l_idx];
        l_idx++;
      } else if (l_idx == n1) {
        data[i] = r_a[r_idx];
        r_idx++;
      } else if (r_a[r_idx] > l_a[l_idx]) {
        data[i] = l_a[l_idx];
        l_idx++;
      } else {
        data[i] = r_a[r_idx];
        r_idx++;
      }
    }
  }

  template <typename T>
  void mi_sort(T& data, int left, int right) {
    if (right - left > 10) {
      int mid = (left + right) / 2;
      mi_sort(data, left, mid);
      mi_sort(data, mid + 1, right);
      merge(data, left, mid, right);
    } else {
      insertSort(data, left, right);
    }
  }
};
#endif