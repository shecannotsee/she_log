#include "seek.h"

#include <stdexcept>

namespace she_log {
namespace detail {
void seek::move_to_start(FILE* file_ptr) {
  const auto fseek_result = ::fseek(file_ptr, 0, SEEK_SET);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
void seek::move(FILE* file_ptr, const uint32_t offset) {
  const auto fseek_result = ::fseek(file_ptr, offset, SEEK_SET);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
void seek::move_to_tail(FILE* file_ptr) {
  const auto fseek_result = ::fseek(file_ptr, 0, SEEK_END);
  if (fseek_result != 0) {
    throw std::runtime_error("fseek failed");
  }
}
}  // namespace detail
}  // namespace she_log
