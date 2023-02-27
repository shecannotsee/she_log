//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_SRC_IO_FOPEN_H_
#define SHE_LOG_SRC_IO_FOPEN_H_

#include <stdio.h>
#include <memory>
#include <make_unique.h>

namespace sheLog {

class Fopen {
 public:
  Fopen();
  ~Fopen();
 private:
  std::unique_ptr<FILE> file_;

};

};// namespace sheLog

#endif //SHE_LOG_SRC_IO_FOPEN_H_
