//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_SRC_LOGCONFIG_H_
#define SHE_LOG_SRC_LOGCONFIG_H_

#include <log_level.h>
#include <log_format.h>
#include <log_output.h>

namespace sheLog {

class logConfig {
 public:
 private:
  log_level   level_;   ///<
  log_format  format_;  ///<
  log_output  output_;  ///<
 public:
  logConfig& set_log_level(log_leve);
  logConfig& set_log_format(log_format);
  logConfig& set_log_format(log_format);


};// class logConfig

};// namespace sheLog

#endif //SHE_LOG_SRC_LOGCONFIG_H_
