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

enum class log_level : unsigned char {
  ALL     = 0,  ///< Open all logs
  TRACE   = 1,  ///<
  DEBUG   = 2,  ///<
  INFO    = 3,  ///< It can be used to output some important information of program operation in the production environment
  WARNING = 4,  ///< Possible error
  ERROR   = 5,  ///< Although an error event occurs, it still does not affect the continuous operation of the system
  FATAL   = 6,  ///< Will cause the application to exit
  OFF     = 7   ///< Close all logs
};


};// namespace sheLog

#endif //SHELOG_SRC_LOG_LEVEL_H_
