/**
 * @file log_format.h
 * @author shecannotsee (shecannotsee@163.com)
 * @brief Log output format
 * @version 0.1
 * @date 2023-02-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef SHE_LOG_SRC_LOG_FORMAT_H_
#define SHE_LOG_SRC_LOG_FORMAT_H_

namespace she_log {

enum class log_format : unsigned char {
  ORIGINAL = 0,  ///< Output original log message
  SHE_LOG  = 1,  ///< Log message with time
  JSON     = 2,  ///< Convert to json output
  END            ///< Marks the end
};

namespace detail {}

};  // namespace she_log

#endif  // SHE_LOG_SRC_LOG_FORMAT_H_
