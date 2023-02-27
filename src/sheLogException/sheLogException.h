//
// Created by shecannotsee on 2023/2/27.
//

#ifndef SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_
#define SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_

#include <exception>
#include <string>

namespace sheLog {

class sheLogException : public std::exception {
 public:
  sheLogException(int error_code,
              const std::string &error_message);// : m_errorCode(errorCode), m_errorMessage(errorMessage) {}

 private:
  int error_code_;
  std::string error_message_;

 public:
  virtual const char *what() const noexcept override;// {return m_errorMessage.c_str();}

  int getErrorCode() const;// {return m_errorCode;};

};// class sheLogException

};// namespace sheLog {

#endif //SHE_LOG_SRC_EXCEPTION_SHELOGEXCEPTION_H_
