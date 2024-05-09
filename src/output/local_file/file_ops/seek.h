#ifndef SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_SEEK_H
#define SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_SEEK_H

#include <stdint.h>
#include <stdio.h>

namespace she_log {
namespace detail {

class seek {
 public:
  static void move_to_start(FILE* file_ptr);
  static void move(FILE* file_ptr, uint32_t offset);
  static void move_to_tail(FILE* file_ptr);
};

}  // namespace detail
}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_SEEK_H
