#include <she_test.h>
#include <time/timeFormat.h>

SHE_TEST(unit_test, time_fomat_test) {
  std::string time = she_log::time::get_format_time();
  std::cout << time << std::endl;
  std::cout << she_log::time::get_format_time() << std::endl;
  return true;
}
