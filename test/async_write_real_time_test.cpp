#include <she_test.h>
#include <unistd.h>

#include <interface.h>


SHE_TEST(unit_test, async_write_real_time_test) {
  try {
    she_log::interface log1("./a.log");
    for (int i = 0; i < 10; ++i) {
      log1.DEBUG("test");
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  } catch (const std::exception& exc) {
    std::cout << exc.what() << std::endl;
  }
}