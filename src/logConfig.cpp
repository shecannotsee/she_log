//
// Created by shecannotsee on 2023/2/28.
//
#include "logConfig.h"
#include <utility>

sheLog::logConfig::logConfig()
    : level_(log_level::DEBUG),
      format_(log_format::DATA_MESSAGE),
      output_(log_output::STD_COUT){
};

sheLog::logConfig::logConfig(const sheLog::logConfig &other)
    : level_(other.level_),
      format_(other.format_),
      output_(other.output_) {
};

sheLog::logConfig &sheLog::logConfig::operator=(const sheLog::logConfig &other) {
  level_ = other.level_;
  format_ = other.format_;
  output_ = other.output_;
  return *this;
}

sheLog::logConfig::logConfig(sheLog::logConfig && other) noexcept
    : level_(other.level_),
      format_(other.format_),
      output_(other.output_){
};

sheLog::logConfig &sheLog::logConfig::operator=(sheLog::logConfig &&other) noexcept {
  if (this != &other) {
    level_ = other.level_;
    format_ = other.format_;
    output_ = other.output_;
  }
  return *this;
};


sheLog::logConfig &sheLog::logConfig::set_log_level(sheLog::log_level level) {
  level_ = level
  return this;
}
sheLog::logConfig &sheLog::logConfig::set_log_format(sheLog::log_format) {
  return <#initializer#>;
}
sheLog::logConfig &sheLog::logConfig::set_log_output(sheLog::log_output) {
  return <#initializer#>;
}
sheLog::log_level sheLog::logConfig::get_log_level(sheLog::log_level) {
  return sheLog::log_level::ERROR;
}
sheLog::log_format sheLog::logConfig::get_log_format(sheLog::log_format) {
  return sheLog::log_format::END;
}
sheLog::log_format sheLog::logConfig::get_log_output(sheLog::log_output) {
  return sheLog::log_format::END;
}
