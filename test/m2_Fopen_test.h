//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_TEST_M2_FOPEN_TEST_H_
#define SHE_LOG_TEST_M2_FOPEN_TEST_H_

#include <io/Fopen.h>
#include <string>


namespace m2_Fopen_test {

int main () {
  she_log::Fopen file("io_test.txt");
  std::string content1 = "2023-02-27 18:49:55 [INFO]The first log.\n";
  file.write(content1);
  std::string content2 = "2023-02-27 18:49:58 [INFO]The second log.\n";
  file.write(content2);

  return 0;
};

};// namespace m2_Fopen_test

#endif //SHE_LOG_TEST_M2_FOPEN_TEST_H_
