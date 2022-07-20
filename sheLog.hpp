#ifndef __SHE_LOG_HPP_
#define __SHE_LOG_HPP_

#define __SHE_TEST_
#ifdef  __SHE_TEST_

#endif//!__SHE_TEST_

#include <string>
#include <iostream>
#include <fstream>
#include "Time/Time.hpp"


//日志level
enum logLevel{
  FATAL,    //0,失败
  ERROR,    //1,错误
  WARNING,  //2,警告
  INFO,     //3,仅记录
  DEBUG     //4,调试
};

class SheLog
{
public:
  SheLog(){
  };

  ~SheLog(){
  };

  void init(std::string path,std::string fileName){
  }

  void logMessage(const std::string &message){

  };

  std::string setLevel(logLevel t){
    switch (t)
    {
    case FATAL:
      return "FATAL  ";
      break;
    case ERROR:
      return "ERROR  ";
      break;
    case WARNING:
      return "WARNING";
      break;
    case INFO:
      return "INFO   ";
      break;
    case DEBUG:
      return "DEBUG  ";
      break;
    default:
      return "???????";
      break;
    }
  };

  void debug(){
#ifdef __SHE_TEST_
    std::cout<<"1\n";
    std::ofstream logFile("./");
    logFile.open(formatDate(),std::ios::out|std::ios::ate);
    if(logFile.is_open()){
      std::cout<<"open\n";
    }else{
      std::cout<<"open failed\n";
    }
    logFile << setLevel(INFO)<<":"<<formatDate()<<"_"<<formatTime()<<"\n";
    logFile << setLevel(WARNING)<<":"<<"\n";
    logFile.close();
#endif//!__SHE_TEST_
  };

private:
  std::string formatDate(){
    std::string t_date = m_time.getYearMonthDay();
    t_date.insert(4,"/");
    t_date.insert(7,"/");
    return t_date;
  }

  std::string formatTime(){
    std::string t_time = m_time.getHourMinuteSeconds();
    t_time.insert(2,":");
    t_time.insert(5,":");
    return t_time;
  }

  uint32_t m_logVersion;
  std::string m_path;
  Time m_time;
  std::ofstream m_write;

};


#endif//!__SHE_LOG_HPP_