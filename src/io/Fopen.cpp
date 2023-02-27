//
// Created by shecannotsee on 2023/2/27.
//

#include "Fopen.h"
#include <sheLogException/sheLogException.h>

sheLog::Fopen::Fopen(const char *filename, const char *mode)
    : file_name_(std::move(std::string(filename))),
      file_(fopen(filename,mode)) {
  if (file_==NULL) {
    std::string error_message = "Open file("+file_name_+") failed.";
    throw sheLogException(1,error_message);
  }
};

sheLog::Fopen::~Fopen() {
  fclose(file_);
  file_ = nullptr;
}
void sheLog::Fopen::write(const std::string& content) {
  if(EOF == fputs(content.c_str(),file_)) {
    std::string error_message = "Failed to write to file("+file_name_+") with fputs.";
    throw sheLogException(2,"Failed to write to file with fputs.");
  };
};


