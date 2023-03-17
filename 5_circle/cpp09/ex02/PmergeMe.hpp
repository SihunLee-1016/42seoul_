#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <cstdlib>  // for strtoul()
#include <climits>  // for INT_MAX

typedef struct s_pair{
  int big;
  int small;
}t_pair;

class PmergeMe {
 private:
  std::set<int> _set;
  std::vector<int> _vector;
  std::deque<int> _deque;

 public:
  PmergeMe(void);
  ~PmergeMe(void);
  void    check_data(int argc, char** argv);
  void    print_after_data();
  void    print_before_data();
  void    sort_vector();
  void    sort_deque();

};
void	save_num(int *list,int ac, char **av);

#endif