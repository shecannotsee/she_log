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
  logConfig(log_level level = log_level::DEBUG,
            log_format format = log_format::DATA_MESSAGE,
            log_output output = log_output::STD_COUT);
  ~logConfig() = default;
  // copy
  logConfig(const logConfig& other);
  logConfig& operator=(const logConfig& other);
  // move
  logConfig(logConfig&& other) noexcept ;
  logConfig& operator=(logConfig&& other) noexcept ;
 private:
  log_level   level_;   ///< log level set
  log_format  format_;  ///< log format set
  log_output  output_;  ///< log output method set
 public:
  logConfig& set_log_level(log_level);
  logConfig& set_log_format(log_format);
  logConfig& set_log_output(log_output);
 public:
  log_level get_log_level(log_level) const;
  log_format get_log_format(log_format) const;
  log_format get_log_output(log_output) const;

};// class logConfig

};// namespace sheLog

#endif //SHE_LOG_SRC_LOGCONFIG_H_
