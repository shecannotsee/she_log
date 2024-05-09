/**
 * @file log_level.h
 * @author shecannotsee (shecannotsee@163.com)
 * @brief Global log level definition
 * @version 0.1
 * @date 2023-02-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHELOG_SRC_LOG_LEVEL_H_
#define SHELOG_SRC_LOG_LEVEL_H_

#include <string>

namespace she_log {

enum class log_level : unsigned char {
  ALL   = 0,  ///< Open all logs
  TRACE = 1,  ///<
  DEBUG = 2,  ///<
  INFO = 3,  ///< It can be used to output some important information of program operation in the production environment
  WARNING = 4,  ///< Possible error
  ERROR   = 5,  ///< Although an error event occurs, it still does not affect the continuous operation of the system
  FATAL   = 6,  ///< Will cause the application to exit
  OFF     = 7   ///< Close all logs
};

namespace detail {
static std::string level_to_str(const log_level level) {
  switch (level) {
    case log_level::TRACE:
      return "TRACE";
    case log_level::DEBUG:
      return "DEBUG";
    case log_level::INFO:
      return "INFO";
    case log_level::WARNING:
      return "WARN";
    case log_level::ERROR:
      return "ERROR";
    case log_level::FATAL:
      return "FATAL";
    default:
      return "UNKNOWN";
  }
}
}  // namespace detail

};  // namespace she_log

#endif  // SHELOG_SRC_LOG_LEVEL_H_
