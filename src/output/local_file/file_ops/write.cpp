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

  // set buffer size: 0
  setbuf(file_ptr_.get(), 0);

  if (EOF == fputs(data.c_str(), file_ptr_.get())) {
    throw std::runtime_error("Failed to write to file with fputs.");
  }
  // buffer -> file
  if (fflush(file_ptr_.get()) != 0) {
    // handle error
  }
}
}  // namespace detail
}  // namespace she_log