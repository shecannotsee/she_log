//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_TEST_M3_TIME_FORMAT_TEST_H_
#define SHE_LOG_TEST_M3_TIME_FORMAT_TEST_H_

#include <time/timeFormat.h>

namespace m3_time_format_test {

int main() {
  std::string time = she_log::time::get_format_time();
  std::cout<<time<<std::endl;
  while (1) {
    std::cout<<she_log::time::get_format_time()<<std::endl;
  };
  return 0;
};

};// namespace m3_time_format_test

#endif //SHE_LOG_TEST_M3_TIME_FORMAT_TEST_H_
