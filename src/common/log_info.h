#ifndef SHE_LOG_COMMON_LOG_INFO_H
#define SHE_LOG_COMMON_LOG_INFO_H

#include <chrono>
#include <string>

#include "../filter/log_level.h"

namespace she_log {

struct log_info {
  log_level level;
  std::chrono::time_point<std::chrono::system_clock> time_point;
  std::string message;
};

}  // namespace she_log

#endif  // SHE_LOG_COMMON_LOG_INFO_H
