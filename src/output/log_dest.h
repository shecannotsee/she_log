#ifndef SHE_LOG_OUTPUT_LOG_DEST_H_
#define SHE_LOG_OUTPUT_LOG_DEST_H_

namespace she_log {

enum class log_dest : unsigned char {
  CONSOLE    = 0,  ///< Use std::cout,the log message will not be persisted under this option
  LOCAL_FILE = 1,  ///< Use io/Fopen.h
  END              ///< Marks the end
};

};  // namespace she_log

#endif  // SHE_LOG_OUTPUT_LOG_DEST_H_
