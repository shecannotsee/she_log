#include <she_test.h>
#include <common/time.h>

SHE_TEST(unit_test, time_fomat_test) {
  std::string time = she_log::detail::time::get_now();
  std::cout << time << std::endl;
  std::cout << she_log::detail::time::get_now() << std::endl;
  return true;
}
