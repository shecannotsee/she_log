#include <she_log.h>

#include <iostream>

int main() {
  std::cout << she_log::fmt("she_log version is:{}", she_log::detail::version);
  return 0;
}
