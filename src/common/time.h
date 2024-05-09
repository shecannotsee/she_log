#ifndef SHE_LOG_COMMON_TIME_H
#define SHE_LOG_COMMON_TIME_H

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

namespace she_log {
namespace detail {

class time {
 public:
  /**
   * @brief Get the formatted date, for example:1999-01-01 00:00:00.000
   * @tparam include_microseconds Do you need to include microseconds?
   * @param time_point Time point. Gets the current point in time by default
   * @return date string
   */
  template <bool include_microseconds = false>
  static std::string get_time_string(
      std::chrono::time_point<std::chrono::system_clock> time_point = std::chrono::system_clock::now()) {
    const std::time_t temp = std::chrono::system_clock::to_time_t(time_point);
    // timestamp -> local time
    const std::tm local_time = *std::localtime(&temp);

    std::stringstream ss;
    // Format the local_time to string
    ss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S");

    // Add ms/us
    const auto remaining_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(time_point.time_since_epoch()) % std::chrono::seconds(1);
    ss << '.' << std::setfill('0') << std::setw(3) << remaining_ms.count();

    if (include_microseconds) {
      const auto remaining_us = std::chrono::duration_cast<std::chrono::microseconds>(time_point.time_since_epoch()) %
                                std::chrono::milliseconds(1);
      ss << std::setfill('0') << std::setw(3) << remaining_us.count();
    }

    return ss.str();
  }
};
}  // namespace detail

}  // namespace she_log

#endif  // SHE_LOG_COMMON_TIME_H