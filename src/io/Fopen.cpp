//
// Created by shecannotsee on 2023/2/27.
//

#include "Fopen.h"
#include <exception/exception.h>

she_log::Fopen::Fopen(const char *filename, const char *mode)
    : file_name_(std::move(std::string(filename))),
      file_(fopen(filename,mode)) {
  if (file_==NULL) {
    std::string error_message = "Open file("+file_name_+") failed.";
    throw exception(1,error_message);
  }
};

she_log::Fopen::~Fopen() {
  fclose(file_);
  file_ = nullptr;
}
void she_log::Fopen::write(const std::string& content) {
  // 设置写缓冲大小为0
  setbuf(file_, NULL);

  if(EOF == fputs(std::string(content+"\n").c_str(),file_)) {
    std::string error_message = "Failed to write to file("+file_name_+") with fputs.";
    throw exception(2,"Failed to write to file with fputs.");
  };
  // 将缓冲区的数据立即写入文件
  if (fflush(file_) != 0) {
    // handle error
  }
};


