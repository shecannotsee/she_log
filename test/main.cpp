//
// Created by shecannotsee on 2023/2/27.
//
#include <iostream>
#include "sheLog_test.h"
#include "time_test.h"

int main() {
  std::cout<< "Test start.\n";
  sheLog_test::main();
  time_test::main();

  std::cout<<"Test done.\n";
  return 0;
};

