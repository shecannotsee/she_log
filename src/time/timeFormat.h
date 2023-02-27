//
// Created by shecannotsee on 2023/2/27.
//

#include <string>
#include <chrono>
#include <tuple>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <time.h>

#ifndef SHE_LOG_SRC_TIME_TIMEFORMAT_H_
#define SHE_LOG_SRC_TIME_TIMEFORMAT_H_

namespace sheLog {

namespace time {

using ms_us = std::tuple<std::chrono::milliseconds,std::chrono::microseconds>;

ms_us get_ms() {
  auto now = std::chrono::system_clock::now();
  return std::make_pair(std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000,
                        std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000);
};

std::string get_format_time() {
  auto time = get_ms();
  std::chrono::system_clock::time_point tp_ms(std::chrono::milliseconds(std::get<0>(time)));
  std::chrono::system_clock::time_point tp_us(std::get<1>(time));
  // 将时间点转换为 time_t
  std::time_t t = std::chrono::system_clock::to_time_t(tp_ms);

  // 将 time_t 转换为 struct tm
  std::tm tm = *std::gmtime(&t);

  // 格式化时间字符串
  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S.") << std::setfill('0') << std::setw(6) << std::get<0>(time).count() % 1000000;
  return oss.str();

};

};// namespace time

};// namespace sheLog

#endif //SHE_LOG_SRC_TIME_TIMEFORMAT_H_
