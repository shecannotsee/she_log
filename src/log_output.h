/**
 * @file log_output_method.h
 * @author shecannotsee (shecannotsee@163.com)
 * @brief Log output method
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SHE_LOG_SRC_LOG_OUTPUT_H_
#define SHE_LOG_SRC_LOG_OUTPUT_H_

namespace sheLog {

enum log_output : unsigned char {
  STD_COUT  = 0,  ///< Use std::cout,the log message will not be persisted under this option
  IO_FOPEN  = 1,  ///< Use io/Fopen.h
  END             ///< Marks the end
};

};// namespace sheLog

#endif //SHE_LOG_SRC_LOG_OUTPUT_H_
