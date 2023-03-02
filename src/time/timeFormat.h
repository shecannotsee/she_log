//
// Created by shecannotsee on 2023/2/27.
//
#ifndef SHE_LOG_SRC_TIME_TIMEFORMAT_H_
#define SHE_LOG_SRC_TIME_TIMEFORMAT_H_

#include <string>
#include <chrono>
#include <tuple>
#include <map>

namespace sheLog {

class time {
 public:
  using ms_us = std::tuple<std::chrono::milliseconds,std::chrono::microseconds>;
  /**
   * @brief Get the current number of milliseconds and microseconds
   * 
   */
  static ms_us get_ms_us();
  /**
   * @brief Fill 0 for single digit
   * 
   */
  static std::string Supplement_0(int param);
  static std::string Supplement_0(double param);
  /**
   * @brief Get the formatted date, for example:
   * 1999-01-01 00:00:00
   * 
   */
  static std::string get_format_time();

};// class time

};// namespace sheLog

#endif //SHE_LOG_SRC_TIME_TIMEFORMAT_H_
