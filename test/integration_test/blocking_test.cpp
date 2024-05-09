/*
integration_test.blocking_test
*/

#include <she_log.h>
#include <she_test.h>
#include <sys/stat.h>

namespace {
const std::string dir_path  = "./output";
const std::string file_path = "./output/blocking_test.txt";

void create_directory(const std::string& dir_path) {
  struct stat st = {0};

  if (stat(dir_path.c_str(), &st) == -1) {
    // 如果目录不存在，创建它
    mkdir(dir_path.c_str(), 0700);
  }
}
}  // namespace

SHE_TEST(integration_test, blocking_test) {
  she_log::logger pen;
  create_directory(dir_path);
  const auto local_file = std::make_shared<she_log::local_file>(file_path);
  local_file->set_format(she_log::log_format::SHE_LOG);
  local_file->set_level(she_log::log_level::ALL);
  pen.add_output_method(local_file);

  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
  }
  std::this_thread::sleep_for(std::chrono::seconds(5));

  return true;
}
