//
// Created by shecannotsee on 24-5-8.
//

#include "time.h"

#include <iomanip>
#include <sstream>

namespace she_log {
namespace detail {

std::string time::get_now(bool include_microseconds) {
  // Get the current time point
  const auto now = std::chrono::system_clock::now();
  // Convert the current point in time to a timestamp
  const std::time_t temp = std::chrono::system_clock::to_time_t(now);
  // timestamp -> local time
  const std::tm local_time = *std::localtime(&temp);

  std::stringstream ss;
  // Format the local_time to string
  ss << std::put_time(&local_time, "%Y-%m-%d %H:%M:%S");

  // Add ms/us
  const auto remaining_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % std::chrono::seconds(1);
  ss << '.' << std::setfill('0') << std::setw(3) << remaining_ms.count();

  if (include_microseconds) {
    const auto remaining_us =
        std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % std::chrono::milliseconds(1);
    ss << std::setfill('0') << std::setw(3) << remaining_us.count();
  }

  return ss.str();
}

}  // namespace detail
}  // namespace she_log
