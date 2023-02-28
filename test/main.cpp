//
// Created by shecannotsee on 2023/2/27.
//
#include <iostream>

#include "m1_she_log_exception_test.h"
#include "m2_Fopen_test.h"
#include "m3_time_format_test.h"
#include "m4_queue_test.h"
#include "m5_interface_test.h"

int main() {
  std::cout<< "Test start.\n";
//  m1_she_log_exception_test::main();
//  m2_Fopen_test::main();
//  m3_time_format_test::main();
//  m4_queue_test::main();
  m5_interface_test::main();
  std::cout<<"Test done.\n";
  return 0;
};

