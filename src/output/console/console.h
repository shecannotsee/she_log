#ifndef SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H
#define SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H

#include <iostream>

#include "../../common/log_info.h"
#include "../../filter/log_level.h"
#include "../output.h"

namespace she_log {

class output;

class console final : public output {
 public:
  console()           = default;
  ~console() override = default;

  void destination(const log_info& log) override {
    const auto log_message = filter_and_format_log_message(log);
    if (log_message.empty()) {
      return;
    }
    // output
    std::cout << log_message;
  }
};

}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H
