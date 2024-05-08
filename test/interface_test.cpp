#include <she_test.h>
#include <interface.h>

#include <time/timeFormat.h>

SHE_TEST(unit_test, interface_test) {
  she_log::interface p("./log.txt");
  p.DEBUG(she_log::time::get_format_time());
  return true;
}