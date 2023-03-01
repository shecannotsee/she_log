//
// Created by shecannotsee on 2023/3/1.
//

#ifndef SHE_LOG_TEST_M6_WRITE_SPEED_TEST_H_
#define SHE_LOG_TEST_M6_WRITE_SPEED_TEST_H_

#include <chrono>
#include <interface.h>
#include <io/Fopen.h>

namespace m6_write_speed_test {

int main() {
  sheLog::interface p("./log.txt");

  auto start_time = std::chrono::steady_clock::now(); // 获取当前的时间点

  while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(1)) {
    p.DEBUG(sheLog::time::get_format_time());
  };

  return 0;
};


};// m6_write_speed_test

#endif //SHE_LOG_TEST_M6_WRITE_SPEED_TEST_H_
