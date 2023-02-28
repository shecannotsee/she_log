//
// Created by shecannotsee on 2023/2/28.
//

#include "interface.h"
#include <thread>
#include <functional>
#include <time/timeFormat.h>

sheLog::interface::interface(const std::string& file_path)
    : file_(file_path.c_str()),
      cfg_(std::move(logConfig())),
      messages_(),
      run_(true) {
  init();
};

void sheLog::interface::init() {
  std::thread c = std::thread(&interface::consumer_thread,this);
  c.detach();
};

void sheLog::interface::consumer_thread() {
  while (run_){
    file_.write(messages_.getMessage());
  }
};

void sheLog::interface::write(const std::string& message) {
  messages_.addMessage(message);
};


void sheLog::interface::TRACE(const std::string& log) {
  this->write(sheLog::time::get_format_time() + "[TRACE]" + log);
};

void sheLog::interface::DEBUG(const std::string& log) {
  this->write(sheLog::time::get_format_time() + "[DEBUG]" + log);
};

void sheLog::interface::INFO(const std::string& log) {
  this->write(sheLog::time::get_format_time() + "[INFO]" + log);
};

void sheLog::interface::WARNING(std::string log) {
  this->write(sheLog::time::get_format_time() + "[WARNING]" + log);
};

void sheLog::interface::ERROR(const std::string& log) {
  this->write(sheLog::time::get_format_time() + "[ERROR]" + log);
};

void sheLog::interface::FATAL(std::string log) {
  this->write(sheLog::time::get_format_time() + "[FATAL]" + log);
};

void sheLog::interface::set_log_level(sheLog::log_level level) {
  cfg_.set_log_level(level);
};

void sheLog::interface::set_log_format(sheLog::log_format format) {
  cfg_.set_log_format(format);
};
;
void sheLog::interface::set_log_output(sheLog::log_output output) {
  cfg_.set_log_output(output);
};

void sheLog::interface::shutdown() {
  run_ = false;
};
