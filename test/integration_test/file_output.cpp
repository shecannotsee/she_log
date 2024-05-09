/*
integration_test.local_file_output_ORIGINAL \
integration_test.local_file_output_SHE_LOG \
integration_test.local_file_output_JSON \
integration_test.local_file_output_ERROR \
integration_test.local_file_level
*/
#include <logger/logger.h>
#include <output/console/console.h>
#include <output/local_file/local_file.h>
#include <she_test.h>
#include <sys/stat.h>

namespace {
const std::string dir_path  = "./output";
const std::string file_path = "./output/local_file_test.txt";

void create_directory(const std::string& dir_path) {
  struct stat st = {0};

  if (stat(dir_path.c_str(), &st) == -1) {
    // 如果目录不存在，创建它
    mkdir(dir_path.c_str(), 0700);
  }
}
}  // namespace

SHE_TEST(integration_test, local_file_output_ORIGINAL) {
  she_log::logger pen;
  create_directory(dir_path);
  const auto local_file = std::make_shared<she_log::local_file>(file_path);
  local_file->set_format(she_log::log_format::ORIGINAL);
  local_file->set_level(she_log::log_level::ALL);
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  console->set_format(she_log::log_format::ORIGINAL);
  console->set_level(she_log::log_level::ALL);
  pen.add_output_method(console);

  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}

SHE_TEST(integration_test, local_file_output_SHE_LOG) {
  she_log::logger pen;
  create_directory(dir_path);
  const auto local_file = std::make_shared<she_log::local_file>(file_path);
  local_file->set_format(she_log::log_format::SHE_LOG);
  local_file->set_level(she_log::log_level::ALL);
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  console->set_format(she_log::log_format::SHE_LOG);
  console->set_level(she_log::log_level::ALL);
  pen.add_output_method(console);

  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}

SHE_TEST(integration_test, local_file_output_JSON) {
  she_log::logger pen;
  create_directory(dir_path);
  const auto local_file = std::make_shared<she_log::local_file>(file_path);
  local_file->set_format(she_log::log_format::JSON);
  local_file->set_level(she_log::log_level::ALL);
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  console->set_format(she_log::log_format::JSON);
  console->set_level(she_log::log_level::ALL);
  pen.add_output_method(console);

  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}

SHE_TEST(integration_test, local_file_output_ERROR) {
  she_log::logger pen;
  create_directory(dir_path);
  const auto local_file = std::make_shared<she_log::local_file>(file_path);
  local_file->set_format(she_log::log_format::END);
  local_file->set_level(she_log::log_level::ALL);
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  console->set_format(she_log::log_format::END);
  console->set_level(she_log::log_level::ALL);
  pen.add_output_method(console);

  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return true;
}

SHE_TEST(integration_test, local_file_level) {
  {
    she_log::logger pen;
    create_directory(dir_path);
    const auto local_file = std::make_shared<she_log::local_file>(file_path);
    local_file->set_format(she_log::log_format::SHE_LOG);
    local_file->set_level(she_log::log_level::ALL);
    pen.add_output_method(local_file);
    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::ALL);
    pen.add_output_method(console);

    pen.record<she_log::log_level::FATAL>("========DEBUG AND INFO=========");

    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<she_log::log_level::DEBUG>(msg);
      pen.record<she_log::log_level::INFO>(msg);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    pen.record<she_log::log_level::FATAL>("============= OFF =============");
  }
  {
    she_log::logger pen;
    create_directory(dir_path);
    const auto local_file = std::make_shared<she_log::local_file>(file_path);
    local_file->set_format(she_log::log_format::SHE_LOG);
    local_file->set_level(she_log::log_level::OFF);
    pen.add_output_method(local_file);
    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::ALL);
    pen.add_output_method(console);

    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<she_log::log_level::DEBUG>(msg);
      pen.record<she_log::log_level::INFO>(msg);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
  {
    she_log::logger pen;
    create_directory(dir_path);
    const auto local_file = std::make_shared<she_log::local_file>(file_path);
    local_file->set_format(she_log::log_format::SHE_LOG);
    local_file->set_level(she_log::log_level::INFO);
    pen.add_output_method(local_file);
    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::ALL);
    pen.add_output_method(console);

    pen.record<she_log::log_level::FATAL>("========== JUST INFO ==========");

    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<she_log::log_level::DEBUG>(msg);
      pen.record<she_log::log_level::INFO>(msg);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }

  return true;
}
