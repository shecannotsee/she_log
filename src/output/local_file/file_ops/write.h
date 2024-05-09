#ifndef SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_WRITE_H
#define SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_WRITE_H

#include <memory>
#include <string>

#include "seek.h"

namespace she_log {
namespace detail {

class write {
 public:
  write() = delete;
  explicit write(const std::string&);
  ~write() = default;
  // copy:off
  write(const write&)            = delete;
  write& operator=(const write&) = delete;
  // move:on
  write(write&&)            = default;
  write& operator=(write&&) = default;

 private:
  std::unique_ptr<FILE, decltype(&fclose)> file_ptr_;

 public:
  void content(const std::string& data) const;
};

}  // namespace detail
}  // namespace she_log

#endif  // SHE_LOG_OUTPUT_LOCAL_FILE_FILE_OPS_WRITE_H
