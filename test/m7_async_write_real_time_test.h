//
// Created by shecannotsee on 23-4-13.
//

#ifndef SHE_LOG_TEST_M7_ASYNC_WRITE_REAL_TIME_TEST_H_
#define SHE_LOG_TEST_M7_ASYNC_WRITE_REAL_TIME_TEST_H_

#include <unistd.h>

namespace m7_async_write_real_time_test {

void main() {
  try {
    she_log::interface log1("./a.log");
    for (int i = 0; i < 10; ++i) {
      log1.DEBUG("test");
      sleep(1);
    }

  } catch (std::exception exc) {
    std::cout << exc.what() <<std::endl;
  }
};

};// namespace m7_async_write_real_time_test

#endif //SHE_LOG_TEST_M7_ASYNC_WRITE_REAL_TIME_TEST_H_
