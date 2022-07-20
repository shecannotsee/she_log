#ifndef __SHE_LOG_HPP_
#define __SHE_LOG_HPP_

#include <stdio.h>
#include <string>
#include <memory>
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
  std::string _path;
  std::string _logFileName;
  Time _time;
  FILE* _log;
 public:
  SheLog(std::string path, std::string logFileName)
      : _time(Time()) ,
        _path(path) ,
        _logFileName(logFileName) ,
        _log(nullptr) {
    _log = fopen((_path+"/"+_logFileName+".log").c_str(),"a+");
    if (_log == nullptr) {
      exit(1);
    }
  };

  ~SheLog() {
    fclose(_log);
  };

  void logMessage(logLevel t,const std::string& message) {
    std::string str = "["+this->setLevel(t)+"]"+ message ;
    fprintf(_log,"[%s]%s\n",_time.getFullDate().c_str(), str.c_str());
    fflush(_log);
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