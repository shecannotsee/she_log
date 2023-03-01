//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_SRC_INTERFACE_H_
#define SHE_LOG_SRC_INTERFACE_H_

#include <string>
#include <thread>
#include <logConfig.h>
#include <io/Fopen.h>
#include <buffer/MessageSafeQueue.h>

namespace sheLog {

class interface {
 public:
  explicit interface(const std::string& file_path);
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
  bool              run_;
  std::thread       get_thread_;
 private:
  void init();
  void consumer_thread();
  void write(const std::string& message);
 public:
  void TRACE(const std::string& log);
  void DEBUG(const std::string& log);
  void INFO(const std::string& log);
  void WARNING(std::string log);
  void ERROR(const std::string& log);
  void FATAL(std::string log);
 public:
  void set_log_level(log_level);
  void set_log_format(log_format);
  void set_log_output(log_output);
 public:
  void shutdown();
};

};// namespace sheLog

#endif //SHE_LOG_SRC_INTERFACE_H_
