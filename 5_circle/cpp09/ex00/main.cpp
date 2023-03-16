#include <sys/wait.h>

#include "BitcoinExchange.hpp"
int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }
  std::ifstream file("data.csv");
  std::string line;

  std::map<std::string, float> data;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date_str;
    float exchange_rate;
    if (line == "date,exchange_rate") continue;
    getline(ss, date_str, ',');
    ss >> exchange_rate;
    data[date_str] = exchange_rate;
    Date prev;
    separateDate(date_str, prev);
    for (int i = 0; i < 2; ++i) {
      std::string new_date;
      modifi_date(prev);
      new_date = tostr(prev.year) + "-";
      if (prev.month <= 9) new_date += "0";
      new_date += tostr(prev.month) + "-";
      if (prev.day <= 9) new_date += "0";
      new_date += tostr(prev.day);
      data[new_date] = exchange_rate;
      new_date.clear();
    }
  }
  file.close();

  // for (std::map<std::string, float>::iterator it = data.begin();
  //      it != data.end(); it++) {
  //   std::cout << it->first << ": " << std::fixed << std::setprecision(2)
  //             << it->second << std::endl;
  // }

  std::ifstream input(av[1]);
  if (input.fail()) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  BitcoinExchange bc(data);
  std::string str;
  while (std::getline(input, str)) {
    bc.read_input(str);
  }
  input.close();
  return 0;
}
