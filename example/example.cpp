//
// Created by shecannotsee on 2023/2/27.
//
#include <iostream>

#include <interface.h>

int main() {
  std::cout<<"example test start.\n";

  sheLog::interface p_log("log.txt");
  p_log.DEBUG("hi");

  std::cout<<"Done.\n";
  return 0;
};
