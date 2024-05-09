#ifndef SHE_LOG_LOGGER_LOGGER_H
#define SHE_LOG_LOGGER_LOGGER_H

#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <vector>

#include "../output/output.h"
#include "../filter/log_level.h"
#include "log_channel.h"

namespace she_log {

class logger {
 public:
  explicit logger() {
    process_thread_ = std::thread(
        [this]() { buffer_.process_logs(outputs_); });
  };
  ~logger() {
    buffer_.stop();
    process_thread_.join();
  }

 private:
  log_channel<log_info> buffer_;                  ///< message(log) queue
  std::thread process_thread_;                    ///< process message(log) thread
  std::vector<std::shared_ptr<output>> outputs_;  // output method

 public:
  template <log_level level>
  void record(const std::string& log_message) {
    log_info temp;
    temp.level      = level;
    temp.time_point = std::chrono::system_clock::now();
    temp.message    = log_message;

    buffer_.push_log(temp);
  }

  void add_output_method(std::shared_ptr<output> output_method) {
    outputs_.emplace_back(output_method);
  }
};
}  // namespace she_log

#endif  // SHE_LOG_LOGGER_LOGGER_H
