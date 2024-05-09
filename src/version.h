#ifndef SHE_LOG_VERSION_H
#define SHE_LOG_VERSION_H

#include <string>

namespace she_log {

namespace detail {

constexpr int major = 0;
constexpr int minor = 0;
constexpr int patch = 1;
const std::string version = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);

}  // namespace detail
}  // namespace she_log

#endif  // SHE_LOG_VERSION_H
