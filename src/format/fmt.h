#ifndef SHE_LOG_FORMAT_FMT_H
#define SHE_LOG_FORMAT_FMT_H

#include <sstream>

namespace she_log {

namespace detail {
// Recursively terminates the function
inline void format_string(std::ostringstream& oss, const std::string& format) {
  oss << format;  // Add the last string to the stream
}

template <typename T, typename... Args>
void format_string(std::ostringstream& oss, const std::string& format, T&& arg, Args&&... args) {
  const size_t pos = format.find("{}");  // find {}

  // no {}
  if (pos == std::string::npos) {
    oss << format;
    return;
  }
  // process {}
  oss << format.substr(0, pos);  // Add the string before the placeholder to the stream
  oss << std::forward<T>(arg);   // Add parameters to the stream
  format_string(oss, format.substr(pos + 2), std::forward<Args>(args)...);  // recursive cal
}

}  // namespace detail


// api
template <typename... Args>
std::string fmt(const std::string& format, Args&&... args) {
  std::ostringstream oss;
  detail::format_string(oss, format, std::forward<Args>(args)...);
  return oss.str();
}

}  // namespace she_log

#endif  // SHE_LOG_FORMAT_FMT_H
