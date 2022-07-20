#ifndef __TIME_HPP_
#define __TIME_HPP_

#include <chrono>
#include <ctime>
#include <string>
#include <memory>

namespace sheLog{
typedef unsigned long long  uint64_t;
typedef unsigned int        uint32_t;

class Time {
 public:
  Time() {
  };
  ~Time() {
  };

public:
  //以字符串格式返回当前日期,格式(去掉所有的-)为:1997-04-03 19:11:00
  std::string getFullDate(){
    return this->getYearMonthDay() + " " + this->getHourMinuteSeconds();
  };

  //以字符串格式返回当前年月日,格式为:1997-04-03
  std::string getYearMonthDay(){
    std::string lalala =  getDate().substr(0,8);
    lalala.insert(4,"-");
    lalala.insert(7,"-");
    return lalala;
  }

  //以字符串格式返回当前时分秒,格式为:12:00:00
  std::string getHourMinuteSeconds(){
    std::string lalala = getDate().substr(8,6);
    lalala.insert(2,":");
    lalala.insert(5,":");
    return lalala;
  }

  void start(){
    _timeFirst = std::chrono::system_clock::now();
  }

  //配合start()函数使用,返回消耗时间,单位为毫秒(1s=1000ms)
  uint64_t getTimeSpentWithMilli(){
    _timeSecond = std::chrono::system_clock::now();
    return (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(_timeSecond)
           - std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(_timeFirst)
           ).count();

  }
  //配合start()函数使用,返回消耗时间,单位为微秒(1s=1000000us)
  uint64_t getTimeSpentWithMicro(){
    _timeSecond = std::chrono::system_clock::now();
    return (_timeSecond-_timeFirst).count();
  }

private:
  std::string getDate(){
    time_t lalala;
    time(&lalala);
    tm* timePtr = localtime(&lalala);
    std::string timeStr;
    //年
    timeStr += std::to_string(timePtr->tm_year+1900);
    //月
    if((timePtr->tm_mon+1)<10){
      timeStr += "0";
    }
    timeStr += std::to_string(timePtr->tm_mon+1);
    //日
    if((timePtr->tm_mday)<10){
      timeStr += "0";
    }
    timeStr += std::to_string(timePtr->tm_mday);
    //时
    if((timePtr->tm_hour)<10){
      timeStr += "0";
    }
    timeStr += std::to_string(timePtr->tm_hour);
    //分
    if((timePtr->tm_min)<10){
      timeStr += "0";
    }
    timeStr += std::to_string(timePtr->tm_min);
    //秒
    if((timePtr->tm_sec)<10){
      timeStr += "0";
    }
    timeStr += std::to_string(timePtr->tm_sec);

    return std::move(timeStr);
  }

  std::chrono::system_clock::time_point _timeFirst;
  std::chrono::system_clock::time_point _timeSecond;
};

};//namespace sheLog
#endif//!__TIME_HPP_
