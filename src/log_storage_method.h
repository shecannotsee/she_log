/**
 * @file log_storage_method.h
 * @author shecannotsee (shecannotsee@163.com)
 * @brief Log storage method definition
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SHE_LOG_SRC_LOG_STORAGE_METHOD_H_
#define SHE_LOG_SRC_LOG_STORAGE_METHOD_H_

namespace sheLog {

enum log_storage : unsigned char {
  LOG_FILE  = 0,  ///< The log will be written to the specified log file
  DATA_BASE = 1,  ///< The log will be written to the database
  END             ///< Marks the end
};

};// namespace sheLog

#endif //SHE_LOG_SRC_LOG_STORAGE_METHOD_H_
