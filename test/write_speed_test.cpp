#include <she_test.h>
#include <chrono>
#include <interface.h>
#include <io/Fopen.h>

#include <time/timeFormat.h>


SHE_TEST(unit_test, write_speed_test) {
  /* interface test */ {
    she_log::interface p("./log_interface.txt");
    auto start_time = std::chrono::steady_clock::now(); // 获取当前的时间点
    while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(1)) {
      p.DEBUG(she_log::time::get_format_time());
    }
  }
  /* fopen test */ {
    she_log::Fopen p("./log_fopen.txt");
    auto start_time = std::chrono::steady_clock::now(); // 获取当前的时间点
    while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(1)) {
      p.write(she_log::time::get_format_time());
    }
  }

  /* test result:The writing method using producer consumer mode is 22% faster than direct writing */

  return true;
}