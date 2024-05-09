#ifndef SHE_LOG_FILTER_LOG_LEVEL_H_
#define SHE_LOG_FILTER_LOG_LEVEL_H_

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

auto level_to_str(log_level level) -> std::string;

auto should_log(log_level global_level, log_level message_level) -> bool;

}  // namespace detail

};  // namespace she_log

#endif  // SHE_LOG_FILTER_LOG_LEVEL_H_
