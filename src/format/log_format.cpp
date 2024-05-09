#include "log_format.h"

#include <cmath>

#include "common/time.h"
namespace she_log {

namespace detail {

auto format_message(const log_info& log, const log_format format) -> std::string {
  switch (format) {
    case log_format::ORIGINAL: {
      return log.message;
    }
    case log_format::SHE_LOG: {
      // 1900-00-00 00:00:00.000[DEBUG]log message
      return time::get_time_string(log.time_point) + "[" + level_to_str(log.level) + "]" + log.message + "\n";
    }
    case log_format::JSON: {
      return "[JSON formatting has not been implemented]" + log.message + "\n";
    }
    default: {
      return "[unknown format]" + log.message + "\n";
    }
  }
}

}  // namespace detail

}  // namespace she_log
