#ifndef SHE_LOG_OUTPUT_FILE_OPS_FILE_H
#define SHE_LOG_OUTPUT_FILE_OPS_FILE_H

#include <string>

namespace she_log {
namespace detail {

class dir {
public:
  static bool exist(const std::string&);
  static void create(const std::string&);
};

class file {
 public:
  static bool exist(const std::string&);
};

}  // namespace detail
}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_FILE_OPS_FILE_H
