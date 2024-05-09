#include <output/local_file/file_ops/file.h>
#include <output/local_file/file_ops/seek.h>
#include <output/local_file/file_ops/write.h>
#include <she_test.h>
#include <sys/stat.h>

namespace {
const std::string dir_path  = "./output";
const std::string file_path = "./output/file_ops_file.txt";

void create_directory(const std::string& dir_path) {
  struct stat st = {0};

  if (stat(dir_path.c_str(), &st) == -1) {
    // 如果目录不存在，创建它
    mkdir(dir_path.c_str(), 0700);
  }
}
}  // namespace

SHE_TEST(unit_test, file_ops_file) {
  using namespace she_log::detail;
  create_directory(dir_path);

  const write handle(file_path);
  handle.content("hello\n");
  handle.content("hello\n");
  handle.content("123421321321\n");
  handle.content("done\n");

  return true;
}
