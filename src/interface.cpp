//
// Created by shecannotsee on 2023/2/28.
//

#include "interface.h"
#include <thread>
#include <functional>
#include <common/time.h>

she_log::interface::interface(const std::string& file_path)
    : file_(file_path.c_str()),
      cfg_(std::move(logConfig())),
      messages_(),
      run_(true),
      get_thread_(&interface::consumer_thread,this) {
};

she_log::interface::~interface() {
  run_ = false;
  if (get_thread_.joinable()) {
    // 为了防止写队列在析构时候没有数据的空等
    this->TRACE("LOG QUIT");
    get_thread_.join();
  }
};

void she_log::interface::consumer_thread() {
  while (run_){
    file_.write(messages_.getMessage());
  }
};

void she_log::interface::write(const std::string& message) {
  messages_.addMessage(message);
};


void she_log::interface::TRACE(const std::string& log) {
  this->write(she_log::time::get_now() + "[TRACE]" + log);
};

void she_log::interface::DEBUG(const std::string& log) {
  this->write(she_log::time::get_now() + "[DEBUG]" + log);
};

void she_log::interface::INFO(const std::string& log) {
  this->write(she_log::time::get_now() + "[INFO]" + log);
};

void she_log::interface::WARNING(std::string log) {
  this->write(she_log::time::get_now() + "[WARNING]" + log);
};

void she_log::interface::ERROR(const std::string& log) {
  this->write(she_log::time::get_now() + "[ERROR]" + log);
};

void she_log::interface::FATAL(std::string log) {
  this->write(she_log::time::get_now() + "[FATAL]" + log);
};

void she_log::interface::set_log_level(she_log::log_level level) {
  cfg_.set_log_level(level);
};

void she_log::interface::set_log_format(she_log::log_format format) {
  cfg_.set_log_format(format);
};
;
void she_log::interface::set_log_output(she_log::log_output output) {
  cfg_.set_log_output(output);
};

void she_log::interface::shutdown() {
  run_ = false;
};
