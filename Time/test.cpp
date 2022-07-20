#include <unistd.h>//sleep
#include <iostream>
#include "Time.hpp"
using namespace std;

int main()
{
  sheLog::Time t;
  //t.debug();
  t.start();
  sleep(3);
  std::cout<<t.getTimeSpentWithMilli()<<"\n";
  std::cout<<t.getTimeSpentWithMicro()<<"\n";
  std::cout<<t.getFullDate()<<"\n";
  std::cout<<t.getYearMonthDay()<<"\n";
  std::cout<<t.getHourMinuteSeconds()<<"\n";

  return 0;
}