#ifndef SHE_LOG_LOGGER_LOGGER_H
#define SHE_LOG_LOGGER_LOGGER_H

#include <chrono>
#include <string>
#include <thread>

#include "filter/log_level.h"
#include "log_channel.h"

struct log_info {
  she_log::log_level level;
  std::chrono::time_point<std::chrono::system_clock> time_point;
  std::string message;
};

namespace she_log {

class logger {
 public:
  logger() {
    process_thread_ = std::thread([this]() { buffer_.process_logs(); });
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
