//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_
#define SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_

#include <exception>
#include <string>

namespace she_log {

class exception : public std::exception {
 public:
  exception(int error_code,
              const std::string &error_message);

 private:
  int error_code_;
  std::string error_message_;

 public:
  virtual const char *what() const noexcept override;

  int get_error_code() const;// {return m_errorCode;};

};// class sheLogException

};// namespace sheLog {

#endif //SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_
