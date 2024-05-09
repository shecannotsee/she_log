//
// Created by shecannotsee on 24-5-9.
//

#ifndef SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H
#define SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H

#include "../output.h"

namespace she_log {

class output;

class console final : public output {
 public:
  console()           = default;
  ~console() override = default;

 public:
  void destination(const log_info& log) override {
  }
};

}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_CONSOLE_CONSOLE_H
