//
// Created by shecannotsee on 24-5-8.
//
#include <logger/logger.h>
#include <she_test.h>

#include <thread>

SHE_TEST(unit_test, logger) {
  she_log::logger p;
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
