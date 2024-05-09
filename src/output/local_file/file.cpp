#include "file.h"

#include <sys/stat.h>

#include <cstdio>
#include <stdexcept>

bool she_log::detail::file::exist(const std::string& file_path) {
  const auto file_ptr = fopen(file_path.c_str(), "r");
  if (file_ptr == nullptr) {
    return false;
  }
  const auto fclose_result = fclose(file_ptr);
  if (fclose_result == EOF) {
    throw std::runtime_error("fclose error");
  }
  return true;
}

bool she_log::detail::dir::exist(const std::string& dir_path) {
  struct stat info {};
  if (stat(dir_path.c_str(), &info) != 0) {
    if (errno == ENOENT) {
      return false;
    } else {
      throw std::runtime_error("Error occurred while checking directory existence");
    }
  }
  return (info.st_mode & S_IFDIR) != 0;
}

void she_log::detail::dir::create(const std::string& dir_path) {
  if (mkdir(dir_path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0) {
    if (errno == EEXIST) {
      throw std::runtime_error("Error occurred while creating directory");
    }
  }
}
