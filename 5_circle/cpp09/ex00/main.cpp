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
    //2023-08-06,0.123123123
    ss >> exchange_rate;

    data[date_str] = exchange_rate;

    //map에 upperbound ->이거를 써서 하는데
    //저는 그냥 다 만들었어요,.

    //데이터가 3일 기준으로 주어지잖아요
    // 2023-08-06에 대한 데이터만 있다고 치면,
    // 08-03, 08-09,
    //근데 여기서, 만약에 2023-08-05 <- 이러면
    // 실제 맵에는 저장이 안되어있잖아요
    //근데 저 함수를 쓰게되면 가장 가까운 값에 해당하는 곳으로 이동?한다해야하나 

    // 1. 맵에 날짜/데이터로 저장.
    // 2. 3일씩 건너띄워져서 만들어지기때문에 그 중간에 해당하는 공백 날짜가 있음
    // 3. 그래서 저는 그냥 그걸 다 만들어줬어요!
    // 4. 그게 지금 여기서부터 file.close 라인까지.
    // 5. 근데 이건 stl을 잘 활용하면 됨!
    
    // map에 upperbound, lowerbound함수를 써라! 라는 내용인거같습니다~

    Date prev;
    separateDate(date_str, prev, 1);

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
