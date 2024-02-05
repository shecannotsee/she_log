//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_SRC_MAKE_UNIQUE_H_
#define SHE_LOG_SRC_MAKE_UNIQUE_H_

#include <memory>

namespace she_log {

namespace CPP11 {

template<typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts &&... params) {
  return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
};

};// namespace CPP11 {

};// namespace sheLog

#endif //SHE_LOG_SRC_MAKE_UNIQUE_H_
