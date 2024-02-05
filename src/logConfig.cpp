//
// Created by shecannotsee on 2023/2/28.
//
#include "logConfig.h"
#include <utility>

she_log::logConfig::logConfig(log_level level,
                             log_format format,
                             log_output output)
    : level_(level),
      format_(format),
      output_(output){
};

she_log::logConfig::logConfig(const she_log::logConfig &other)
    : level_(other.level_),
      format_(other.format_),
      output_(other.output_) {
};

she_log::logConfig &she_log::logConfig::operator=(const she_log::logConfig &other) {
  level_ = other.level_;
  format_ = other.format_;
  output_ = other.output_;
  return *this;
}

she_log::logConfig::logConfig(she_log::logConfig && other) noexcept
    : level_(other.level_),
      format_(other.format_),
      output_(other.output_){
};

she_log::logConfig &she_log::logConfig::operator=(she_log::logConfig &&other) noexcept {
  if (this != &other) {
    level_ = other.level_;
    format_ = other.format_;
    output_ = other.output_;
  }
  return *this;
};


she_log::logConfig &she_log::logConfig::set_log_level(she_log::log_level level) {
  level_ = level;
  return *this;
};

she_log::logConfig &she_log::logConfig::set_log_format(she_log::log_format format) {
  format_ = format;
  return *this;
};

she_log::logConfig &she_log::logConfig::set_log_output(she_log::log_output output) {
  output_ = output;
  return *this;
}
she_log::log_level she_log::logConfig::get_log_level(she_log::log_level) const {
  return level_;
}
she_log::log_format she_log::logConfig::get_log_format(she_log::log_format) const {
  return format_;
}
she_log::log_output she_log::logConfig::get_log_output(she_log::log_output) const {
  return output_;
}
