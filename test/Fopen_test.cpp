#include <she_test.h>
#include <output/Fopen.h>
#include <string>

SHE_TEST(unit_test, Fopen_test) {
  she_log::Fopen file("io_test.txt");
  std::string content1 = "2023-02-27 18:49:55 [INFO]The first log.\n";
  file.write(content1);
  std::string content2 = "2023-02-27 18:49:58 [INFO]The second log.\n";
  file.write(content2);

  return true;
}
