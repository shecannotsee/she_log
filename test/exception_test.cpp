#include <she_test.h>
#include <sheLogException/sheLogException.h>

namespace {
void my_function() {
  // some code that might throw an sheLogException
  throw she_log::sheLogException(42, "An error occurred.");
}
}

SHE_TEST(unit_test, exception_test) {
  try {
    my_function();
  } catch (const she_log::sheLogException& exc) {
    std::cerr << exc.what();
    return true;
  }

  return true;
}
