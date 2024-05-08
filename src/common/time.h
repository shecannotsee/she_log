//
// Created by shecannotsee on 24-5-8.
//

#ifndef SHE_LOG_COMMON_TIME_H
#define SHE_LOG_COMMON_TIME_H

#include <chrono>
#include <string>

namespace she_log {
class time {
 public:
  /**
   * @brief Get the formatted date, for example:1999-01-01 00:00:00.000
   * @param include_microseconds Do you need to include microseconds?
   * @return date string
   */
  static std::string get_now(bool include_microseconds = false);
};
}  // namespace she_log

#endif  // SHE_LOG_COMMON_TIME_H