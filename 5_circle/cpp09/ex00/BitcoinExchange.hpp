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
  BitcoinExchange(BitcoinExchange const& tmp);
  BitcoinExchange& operator=(BitcoinExchange const& tmp);

 public:
  BitcoinExchange(void);
  BitcoinExchange(std::map<std::string, float> tmp);
  ~BitcoinExchange(void);
  void read_input(std::string str);
};

std::string tostr(int num);
float my_stof(const std::string& str);
void separateDate(const std::string& dateString, Date& date, int flag);
void modifi_date(Date& prev);
void RemoveTabSpace(std::string& str);
int validate_input_date(Date& tmp);
#endif