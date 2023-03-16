#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

struct Date {
  int year;
  int month;
  int day;
};

class BitcoinExchange {
 private:
  std::map<std::string, float> data;

 public:
  BitcoinExchange(void);
  BitcoinExchange(std::map<std::string, float> tmp);
  ~BitcoinExchange(void);
  void read_input(std::string str);
};

int validate_input_date(Date& tmp);
#endif