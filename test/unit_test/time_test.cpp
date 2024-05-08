//
// Created by shecannotsee on 24-5-8.
//
#include <common/time.h>
#include <she_test.h>

#include <thread>

SHE_TEST(unit_test, time) {
  std::cout << "show now with ms:";
  std::cout << she_log::detail::time::get_time_string<>() << std::endl;
  std::cout << "show now with us:";
  std::cout << she_log::detail::time::get_time_string<true>() << std::endl << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "time_point get:\n\t";
  std::chrono::time_point<std::chrono::system_clock> time_point = std::chrono::system_clock::now();
  std::cout << she_log::detail::time::get_time_string<true>(time_point) << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  std::cout << "time_point get(after 100ms):\n\t";
  time_point = std::chrono::system_clock::now();
  std::cout << she_log::detail::time::get_time_string<true>(time_point) << std::endl;

  return true;
}
