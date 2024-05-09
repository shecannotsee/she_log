//
// Created by shecannotsee on 24-5-8.
//
#include <logger/logger.h>
#include <she_test.h>

#include <thread>

#include "common/time.h"

namespace {

class output_test : public she_log::output {
 public:
  void destination(const she_log::log_info& log) override {
    std::cout << she_log::detail::time::get_time_string(log.time_point) << "["
              << she_log::detail::level_to_str(log.level) << "]" << log.message << std::endl;
  }
};

}  // namespace

SHE_TEST(unit_test, logger) {
  she_log::logger pen;

  pen.add_output_method(std::make_shared<output_test>());
  pen.add_output_method(std::make_shared<output_test>());
  pen.add_output_method(std::make_shared<output_test>());

  using namespace she_log;
  for (int i = 0; i < 10;) {
    pen.record<log_level::DEBUG>(std::to_string(++i));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}
