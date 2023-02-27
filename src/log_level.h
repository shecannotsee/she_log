/**
 * @file log_level.h
 * @author shecannotsee (shecannotsee@163.com)
 * @brief Global log level definition
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SHELOG_SRC_LOG_LEVEL_H_
#define SHELOG_SRC_LOG_LEVEL_H_

namespace sheLog {

enum log_level : unsigned char {
  ALL     = 0,
  TRACE   = 1,
  DEBUG   = 2,
  INFO    = 3,
  WARNING = 4,
  ERROR   = 5,
  FATAL   = 6,
  OFF     = 7
};


};// namespace sheLog

#endif //SHELOG_SRC_LOG_LEVEL_H_
