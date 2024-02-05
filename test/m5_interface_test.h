//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_TEST_M5_INTERFACE_TEST_H_
#define SHE_LOG_TEST_M5_INTERFACE_TEST_H_

#include <interface.h>

namespace m5_interface_test {

int main() {
  she_log::interface p("./log.txt");
  p.DEBUG(she_log::time::get_format_time());
  return 0;
};

};// m5_interface_test

#endif //SHE_LOG_TEST_M5_INTERFACE_TEST_H_
