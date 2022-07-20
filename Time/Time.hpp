#ifndef __TIME_HPP_
#define __TIME_HPP_

#define __SHE_TEST_
#ifdef  __SHE_TEST_
#include <iostream>
#include <unistd.h>//sleep
#endif//!__SHE_TEST_

#include <chrono>
#include <ctime>
#include <string>

typedef unsigned long long  uint64_t;
typedef unsigned int        uint32_t;

class Time
{
public:
  Time(){
  };
  ~Time(){
  };

public:
  //以字符串格式返回当前日期,格式(去掉所有的-)为:1997-04-03-19-11-00
  std::string getFullDate(){
    return getDate();
  };

  //以字符串格式返回当前年月日,格式(去掉所有的-)为:1997-04-03
  std::string getYearMonthDay(){
    return getDate().substr(0,8);
  }

  //以字符串格式返回当前时分秒,格式(去掉所有的-)为:12-00-00
  std::string getHourMinuteSeconds(){
    return getDate().substr(8,6);
  }

  void start(){
    m_timeFirst = std::chrono::system_clock::now();
  }

  //配合start()函数使用,返回消耗时间,单位为毫秒(1s=1000ms)
  uint64_t getTimeSpentWithMilli(){
    m_timeSecond = std::chrono::system_clock::now();
    return (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(m_timeSecond) 
           - std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(m_timeFirst)
           ).count();
    
  }
  //配合start()函数使用,返回消耗时间,单位为微秒(1s=1000000us)
  uint64_t getTimeSpentWithMicro(){
    m_timeSecond = std::chrono::system_clock::now();
    return (m_timeSecond-m_timeFirst).count();
  }

  //用来测试
  void debug(){
#ifdef __SHE_TEST_
    std::chrono::duration<int, std::milli>  ms_record;//milli-毫秒,micro-微秒,nano-纳秒
    ms_record = std::chrono::duration<int, std::milli>(3000);//赋值
    std::cout<<ms_record.count()<<"\n";//取值
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    std::cout << "current_time = " << current_time.time_since_epoch().count() << "\n";

    m_timeFirst = std::chrono::system_clock::now();//第一次获取当前时间
    sleep(3);//sleep  3s
    m_timeSecond = std::chrono::system_clock::now();//第二次获取当前时间
    //微秒
    std::cout<<(m_timeSecond-m_timeFirst).count()<<"\n";
    //毫秒
    std::cout<<static_cast<uint32_t>(
                (std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(m_timeSecond) 
                - std::chrono::time_point_cast<std::chrono::duration<int,std::ratio<1,1000>>>(m_timeFirst)
                ).count())<<"\n";
#endif//!__SHE_TEST_
  };

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

    return timeStr;
  }

  std::chrono::system_clock::time_point m_timeFirst;
  std::chrono::system_clock::time_point m_timeSecond;
};


#endif//!__TIME_HPP_