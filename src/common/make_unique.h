#ifndef SHE_LOG_SRC_MAKE_UNIQUE_H_
#define SHE_LOG_SRC_MAKE_UNIQUE_H_

#if __cplusplus >= 201103L && __cplusplus < 201402L

#include <memory>

namespace std {
template <typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params) {
  return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}
} // namespace std

#endif

#endif //SHE_LOG_SRC_MAKE_UNIQUE_H_
