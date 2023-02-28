//
// Created by shecannotsee on 2023/2/27.
//
#include "timeFormat.h"

sheLog::time::ms_us sheLog::time::get_ms_us() {
  auto now = std::chrono::system_clock::now();
  return std::make_pair(std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000,
                        std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()) % 1000);
};


std::string sheLog::time::Supplement_0(int param) {
  if (param>=0&&param<=9) {
    return "0" + std::to_string(param);
  } else {
    return std::to_string(param);
  }
};

std::string sheLog::time::get_format_time() {
  auto now = std::chrono::system_clock::now();
  // 将时间点转换为 time_t 类型
  std::time_t t = std::chrono::system_clock::to_time_t(now);
  // 将 time_t 类型转换为本地时间 struct tm
  std::tm local_time = *std::localtime(&t);
  std::string ret;
  ret += Supplement_0(local_time.tm_year + 1900)+"-";
  ret += Supplement_0(local_time.tm_mon + 1)+"-";
  ret += Supplement_0(local_time.tm_mday)+" ";
  ret += Supplement_0(local_time.tm_hour )+":";
  ret += Supplement_0(local_time.tm_min )+":";
  ret += Supplement_0(local_time.tm_sec );
  return ret;
};
