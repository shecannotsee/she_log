//
// Created by shecannotsee on 24-5-8.
//
#include <logger/logger.h>
#include <she_test.h>

#include <thread>

#include "common/time.h"

SHE_TEST(unit_test, logger) {
  she_log::logger p([](const she_log::log_info& log_info) {
    std::cout << she_log::detail::time::get_time_string(log_info.time_point) << "["
              << she_log::detail::level_to_str(log_info.level) << "]" << log_info.message << std::endl;
  });

  using namespace she_log;
  for (int i = 0; i < 10; ++i) {
    p.log<log_level::DEBUG>(std::to_string(++i));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}
