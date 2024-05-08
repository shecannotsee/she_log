//
// Created by shecannotsee on 24-5-8.
//
#include <logger/logger.h>
#include <she_test.h>

#include <thread>

SHE_TEST(unit_test, logger) {
  const std::function<void(she_log::log_info)> process = [](she_log::log_info log_info) {

  };
  she_log::logger p([](const she_log::log_info& log_info) { std::cout << "process:" << log_info.message << std::endl; });

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  p.log<she_log::log_level::ALL>("123");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  return true;
}
