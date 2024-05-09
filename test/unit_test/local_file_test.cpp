//
// Created by shecannotsee on 24-5-8.
//

#include <output/local_file/file.h>
#include <output/local_file/seek.h>
#include <output/local_file/write.h>
#include <she_test.h>

namespace {
const std::string dir_path  = "./test";
const std::string file_path = dir_path + "/file_test.txt";
}  // namespace

SHE_TEST(unit_test, file_ops_file) {
  using namespace she_log::detail;
  auto ret = dir::exist(dir_path);
  if (ret == false) {
    printf("dir:%s not exist...\n", dir_path.c_str());
    dir::create(dir_path);
  }
  ret = file::exist(file_path);
  if (ret == false) {
    printf("file:%s not exist...\n", file_path.c_str());
  }

  const write handle(file_path);
  handle.content("hello\n");
  handle.content("hello\n");
  handle.content("123421321321\n");

  return true;
}
