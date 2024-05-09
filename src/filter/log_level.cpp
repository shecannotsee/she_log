#include "log_level.h"
namespace she_log {
namespace detail {

std::string level_to_str(const log_level level) {
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

bool should_log(log_level global_level, log_level message_level) {
  if (global_level == log_level::OFF) {
    return false;
  }

  if (global_level == log_level::ALL) {
    return true;
  }

  // message_level >= global_level, return true
  return static_cast<int>(message_level) >= static_cast<int>(global_level);
}

}  // namespace detail
}  // namespace she_log
