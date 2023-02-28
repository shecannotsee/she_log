//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_SRC_INTERFACE_H_
#define SHE_LOG_SRC_INTERFACE_H_

#include <string>
#include <logConfig.h>
#include <io/Fopen.h>
#include <buffer/MessageSafeQueue.h>

namespace sheLog {

class interface {
 public:
  interface();
  ~interface();
  // disable copy
  interface(const interface& x) = delete;
  interface& operator=(const interface& x) = delete;
  // disable move
  interface(interface&&) = delete;
  interface& operator=(interface&& x) = delete;

 private:
  logConfig         cfg_;
  Fopen             file_;
  MessageSafeQueue  messages_;
 private:
  void init();
  void consumer_thread();
 public:
  void TRACE(std::string log);
  void DEBUG(std::string log);
  void INFO(std::string log);
  void WARNING(std::string log);
  void ERROR(std::string log);
  void FATAL(std::string log);
 public:
  void set_log_level(log_level);
  void set_log_format(log_format);
  void set_log_output(log_output);
};

};// namespace sheLog

#endif //SHE_LOG_SRC_INTERFACE_H_
