//
// Created by shecannotsee on 24-5-9.
//

#ifndef SHE_LOG_OUTPUT_OUTPUT_H
#define SHE_LOG_OUTPUT_OUTPUT_H

#include "../filter/log_level.h"
#include "../format/log_format.h"

namespace she_log {

struct log_info;

class output {
 public:
  output()          = default;
  virtual ~output() = default;

 private:
  log_level level_   = log_level::ALL;       ///< default value
  log_format format_ = log_format::SHE_LOG;  ///< default value

 public:
  virtual void set_level(const log_level level) {
    level_ = level;
  }
  virtual void set_format(const log_format format) {
    format_ = format;
  }

  virtual void destination(const log_info& log) = 0;
};

}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_OUTPUT_H
