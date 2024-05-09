//
// Created by shecannotsee on 24-5-9.
//

#ifndef SHE_LOG_OUTPUT_LOCAL_FILE_LOCAL_FILE_H
#define SHE_LOG_OUTPUT_LOCAL_FILE_LOCAL_FILE_H

#include <string>

#include "../../common/log_info.h"
#include "../output.h"
#include "file_ops/write.h"

namespace she_log {

class local_file final : public output {
 public:
  explicit local_file(const std::string& file_path) : output(), handle_write_(file_path) {
  }
  ~local_file() override = default;

 private:
  detail::write handle_write_;

 public:
  void destination(const log_info& log) override {
    const auto log_message = filter_and_format_log_message(log);
    if (log_message.empty()) {
      return;
    }
    // output
    handle_write_.content(log_message);
  }
};

}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_LOCAL_FILE_LOCAL_FILE_H
