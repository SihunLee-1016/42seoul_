#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iomanip>
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

std::string tostr(int num);
void separateDate(const std::string& dateString, Date& date);
void modifi_date(Date& prev);
void RemoveTabSpace(std::string& str);
int validate_input_date(Date& tmp);
#endif