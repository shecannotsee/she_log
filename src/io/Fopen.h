//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_SRC_IO_FOPEN_H_
#define SHE_LOG_SRC_IO_FOPEN_H_

#include <stdio.h>
#include <memory>
#include <make_unique.h>

namespace she_log {

class Fopen {
 public:
  Fopen() = delete;
  Fopen(const char *filename,const char *mode = "a+");
  ~Fopen();

 private:
  FILE* file_;
  std::string file_name_;

 public:
  void write(const std::string& content);
};

};// namespace sheLog

#endif //SHE_LOG_SRC_IO_FOPEN_H_
