#include <iostream>
#include <sheLog.hpp>

namespace sheLog_test {

int main() {
  sheLog::SheLog t("./", "log");
  t.logMessage(sheLog::logLevel::DEBUG, "123");

  return 0;
};// int main

};// namespace sheLog_test
