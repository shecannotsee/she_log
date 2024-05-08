#ifndef SHE_LOG_LOGGER_LOGGER_H
#define SHE_LOG_LOGGER_LOGGER_H

#include <chrono>
#include <functional>
#include <string>
#include <thread>

#include "filter/log_level.h"
#include "log_channel.h"

namespace she_log {

class logger {
 public:
  explicit logger(std::function<void(log_info)> process_func) {
    process_thread_ = std::thread(
        [this, &process_func]() { buffer_.process_logs(std::forward<std::function<void(log_info)>>(process_func)); });
  };
  ~logger() {
    buffer_.stop();
    process_thread_.join();
  }

 private:
  log_channel<log_info> buffer_;
  std::thread process_thread_;

 public:
  template <log_level level>
  void log(const std::string& log_message) {
    log_info temp;
    temp.level      = level;
    temp.time_point = std::chrono::system_clock::now();
    temp.message    = log_message;

    buffer_.push_log(temp);
  }
};
}  // namespace she_log

#endif  // SHE_LOG_LOGGER_LOGGER_H
