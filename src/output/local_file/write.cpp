#include "write.h"

#include <stdexcept>

namespace she_log {
namespace detail {
write::write(const std::string& file_path) : file_ptr_(fopen(file_path.c_str(), "a+"), &fclose) {
  if (file_ptr_ == nullptr) {
    throw std::runtime_error("fopen error: " + file_path);
  }
}

void write::content(const std::string& data) const {
  if (file_ptr_ == nullptr) {
    throw std::runtime_error("file_ptr_ handle is nullptr");
  }

  const auto len = data.size();
  if (fwrite(data.c_str(), sizeof(char), data.size(), file_ptr_.get()) != len) {
    throw std::runtime_error("fwrite failed");
  }
}
}  // namespace detail
}  // namespace she_log