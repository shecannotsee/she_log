//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_TEST_M5_INTERFACE_TEST_H_
#define SHE_LOG_TEST_M5_INTERFACE_TEST_H_

#include <interface.h>
#include <chrono>

namespace m5_interface_test {

int main() {
  sheLog::interface p("./log.txt");

  p.DEBUG(sheLog::time::get_format_time());
  p.shutdown();
  return 0;
};

};// m5_interface_test

#endif //SHE_LOG_TEST_M5_INTERFACE_TEST_H_
