//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_TEST_M1_SHE_LOG_EXCEPTION_TEST_H_
#define SHE_LOG_TEST_M1_SHE_LOG_EXCEPTION_TEST_H_

#include <sheLogException/sheLogException.h>

namespace m1_she_log_exception_test {

void myFunction() {
  // some code that might throw an sheLogException
  throw she_log::sheLogException(42, "An error occurred.");
}

int main() {

  try {
    myFunction();
  } catch (const she_log::sheLogException& exc) {
    std::cerr<<exc.what();
  };


  return 0;
};

};// namespace m1_she_log_exception_test

#endif //SHE_LOG_TEST_M1_SHE_LOG_EXCEPTION_TEST_H_
