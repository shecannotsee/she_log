#ifndef __SHE_LOG_HPP_
#define __SHE_LOG_HPP_

#include <string>
#include "Time/Time.hpp"

namespace sheLog {
//日志level
enum logLevel{
  FATAL,    //0,失败
  ERROR,    //1,错误
  WARNING,  //2,警告
  INFO,     //3,仅记录
  DEBUG     //4,调试
};

class SheLog {
 private:
  uint32_t _logVersion;
  std::string _path;
  Time _time;
 public:
  SheLog() {
  };

  ~SheLog() {
  };

  void logMessage(const std::string &message) {

  };

  std::string setLevel(logLevel t){
    switch (t) {
      case FATAL:
        return "FATAL";
        break;
      case ERROR:
        return "ERROR";
        break;
      case WARNING:
        return "WARNING";
        break;
      case INFO:
        return "INFO";
        break;
      case DEBUG:
        return "DEBUG";
        break;
      default:
        return "???????";
        break;
    }
  };


};//class sheLog

};//namespace sheLog

#endif//!__SHE_LOG_HPP_