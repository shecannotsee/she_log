#include <iostream>
#include "../src/sheLog.hpp"

int main()
{
  sheLog::SheLog t("./","log");
  t.logMessage(sheLog::logLevel::DEBUG,"123");

  return 0;
}
