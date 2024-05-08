#include <she_test.h>
#include <interface.h>

#include <common/time.h>

SHE_TEST(unit_test, interface_test) {
  she_log::interface p("./log.txt");
  p.DEBUG(she_log::time::get_now());
  return true;
}
