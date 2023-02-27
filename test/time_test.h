#include <iostream>
#include <unistd.h>//sleep
#include <time/Time.hpp>

namespace time_test {

int main() {
  sheLog::Time t;
  //t.debug();
  t.start();
  sleep(3);
  std::cout << t.getTimeSpentWithMilli() << "\n";
  std::cout << t.getTimeSpentWithMicro() << "\n";
  std::cout << t.getFullDate() << "\n";
  std::cout << t.getYearMonthDay() << "\n";
  std::cout << t.getHourMinuteSeconds() << "\n";

  return 0;
};// int main

};// time_test.cpp
