//
// Created by shecannotsee on 2023/2/27.
//

#include <string>
#include <chrono>
#include <tuple>
#include <map>

#ifndef SHE_LOG_SRC_TIME_TIMEFORMAT_H_
#define SHE_LOG_SRC_TIME_TIMEFORMAT_H_

namespace sheLog {

namespace time {

using ms_us = std::tuple<std::chrono::milliseconds,std::chrono::microseconds>;

static std::map<std::string, std::string> month_map = {
    {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
    {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
    {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
};


ms_us get_ms() {
  auto now = std::chrono::system_clock::now();
  return std::make_pair(std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000,
                        std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000);
};

std::string get_format_time() {
  auto now = std::chrono::system_clock::now();
  std::time_t tm_1 = std::chrono::system_clock::to_time_t(now);
  /*012(week) 456(month) 89(day) 11-18(time) 20-23(year)*/
  std::string today = std::ctime(&tm_1);
  std::string ret;
  ret += today.substr(20,4)+" ";
  ret += month_map[today.substr(4,3)]+" ";
  ret += today.substr(8,2)+" ";
  ret += today.substr(11,8);
  return ret;

};

};// namespace time

};// namespace sheLog

#endif //SHE_LOG_SRC_TIME_TIMEFORMAT_H_
