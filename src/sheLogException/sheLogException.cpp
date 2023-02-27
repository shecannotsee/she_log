//
// Created by shecannotsee on 2023/2/27.
//

#include "sheLogException.h"

sheLog::sheLogException::sheLogException(int error_code, const std::string& error_message)
    : error_code_(error_code),
      error_message_(std::move(std::string("sheLog error["+std::to_string(error_code_)+"]"+error_message))) {
};

const char *sheLog::sheLogException::what() const noexcept {
  return error_message_.c_str();
};

int sheLog::sheLogException::getErrorCode() const {
  return error_code_;
}
