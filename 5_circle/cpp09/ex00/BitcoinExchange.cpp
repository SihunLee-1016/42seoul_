#include "BitcoinExchange.hpp"

std::string tostr(int num) {
  std::stringstream ss;
  std::string str;
  ss << num;
  ss >> str;
  return (str);
}

float my_stof(const std::string& str) {
  float result;
  std::stringstream ss(str);
  if (!(ss >> result) || !ss.eof()) return -1;
  return result;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& tmp) { (void)tmp; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& tmp) {
  BitcoinExchange* b = NULL;
  (void)tmp;

  return *b;
}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> tmp) {
  data = tmp;
}

void separateDate(const std::string& dateString, Date& date, int flag) {
  if (flag == 0 && dateString.size() != 10) {
    date.year = 0;
    return;
  }

  std::string yearString = dateString.substr(0, 4);

  date.year = 0;
  for (int i = 0; i < 4; ++i) {
    date.year = date.year * 10 + (yearString[i] - '0');
  }

  std::string monthString = dateString.substr(5, 2);

  date.month = 0;
  for (int i = 0; i < 2; ++i) {
    date.month = date.month * 10 + (monthString[i] - '0');
  }

  std::string dayString = dateString.substr(8, 2);
  date.day = 0;
  for (int i = 0; i < 2; ++i) {
    date.day = date.day * 10 + (dayString[i] - '0');
  }
}

void modifi_date(Date& prev) {
  if (prev.month == 12 && prev.day == 31) {
    prev.day = 1;
    prev.month = 1;
    prev.year += 1;
  } else if ((prev.month == 1 || prev.month == 3 || prev.month == 5 ||
              prev.month == 7 || prev.month == 8 || prev.month == 10) &&
             prev.day == 31) {
    prev.day = 1;
    prev.month += 1;
  } else if ((prev.month == 4 || prev.month == 6 || prev.month == 9 ||
              prev.month == 11) &&
             prev.day == 30) {
    prev.day = 1;
    prev.month += 1;
  } else if (prev.month == 2 && prev.day >= 28) {
    if (prev.year % 4 == 0) {
      if (prev.day == 28)
        prev.day += 1;
      else {
        prev.day = 1;
        prev.month += 1;
      }
    } else {
      prev.day = 1;
      prev.month += 1;
    }
  } else
    prev.day += 1;
}

int validate_input_date(Date& tmp) {
  if (tmp.year < 2009 || tmp.year > 2022) return 1;
  if (tmp.month > 12 || tmp.month < 1) return 1;
  if (tmp.day < 1 || tmp.day > 31) return 1;

  if (tmp.month == 1 || tmp.month == 3 || tmp.month == 5 || tmp.month == 7 ||
      tmp.month == 8 || tmp.month == 10 || tmp.month == 12) {
    if (tmp.day > 31) return 1;
  } else if (tmp.month == 4 || tmp.month == 6 || tmp.month == 9 ||
             tmp.month == 11) {
    if (tmp.day > 30) return 1;
  } else if (tmp.month == 2) {
    if (tmp.year % 4 == 0) {
      if (tmp.day > 29) return 1;
    } else {
      if (tmp.day > 28) return 1;
    }
  } else
    return 1;
  return 0;
}

void RemoveTabSpace(std::string& str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == '\t' || str[i] == ' ') {
      str.erase(i, 1);
      --i;
    }
  }
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::read_input(std::string str) {
  if (str == "date | value") return;
  Date tmp;
  std::string date_str;
  std::string value_str;
  float value;

  RemoveTabSpace(str);

  size_t pos = str.find("|");
  if (pos == std::string::npos) {
    std::cout << "Error : invalid format" << std::endl;
    return;
  }

  date_str = str.substr(0, pos);
  value_str = str.substr(pos + 1, str.length());

  separateDate(date_str, tmp, 0);
  if (validate_input_date(tmp) == 1) {
    std::cout << "Error : invalid date => " << date_str << std::endl;
    return;
  }
  value = my_stof(value_str);

  if (value < 1 || value > 999) {
    std::cout << "Error : Out of Range." << std::endl;
    return;
  }
  RemoveTabSpace(date_str);
  std::cout << date_str << "=> " << value << " = " << data[date_str] * value
            << std::endl;
}
