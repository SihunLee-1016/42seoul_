#include "RPN.hpp"

int main(int ac, char **av) {
  if (ac != 2) return 1;
  std::stack<int> exp;
  int n_cnt = 0;
  int e_cnt = 0;

  for (int i = 0; av[1][i]; ++i) {
    if (av[1][i] >= '0' && av[1][i] <= '9')
      n_cnt += 1;
    else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' ||
             av[1][i] == '/')
      e_cnt += 1;
  }
  if (n_cnt != e_cnt + 1) {
    std::cout << "Invalid expression" << std::endl;
    return 1;
  }
  int i = 0;
  while (av[1][i]) {
    if (av[1][i] == ' ') {
      ++i;
      continue;
    }
    if (av[1][i] >= '0' && av[1][i] <= '9')
      exp.push(atoi(&av[1][i]));
    else if (av[1][i] == '+' || av[1][i] == '-' || av[1][i] == '*' ||
             av[1][i] == '/') {
      int num1 = exp.top();
      exp.pop();
      int num2 = exp.top();
      exp.pop();
      if (av[1][i] == '+')
        exp.push(num2 + num1);
      else if (av[1][i] == '-')
        exp.push(num2 - num1);
      else if (av[1][i] == '*')
        exp.push(num2 * num1);
      else
        exp.push(num2 / num1);
    } else {
      std::cout << "ERROR" << std::endl;
      return 1;
    }
    i++;
  }
  std::cout << exp.top() << std::endl;
}
