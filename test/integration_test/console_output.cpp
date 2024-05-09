#include <logger/logger.h>
#include <output/console/console.h>
#include <she_test.h>

SHE_TEST(integration_test, console_output_ORIGINAL) {
  she_log::logger pen;

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

SHE_TEST(integration_test, console_output_SHE_LOG) {
  she_log::logger pen;

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

SHE_TEST(integration_test, console_output_JSON) {
  she_log::logger pen;

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

SHE_TEST(integration_test, console_output_ERROR) {
  she_log::logger pen;

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

SHE_TEST(integration_test, console_level) {
  std::cout<<"========DEBUG AND INFO=========\n";
  {
    she_log::logger pen;

    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::ALL);
    pen.add_output_method(console);

    using namespace she_log;
    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<log_level::DEBUG>(msg);
      pen.record<log_level::INFO>(msg);
    }
  }
  std::cout<<"============= OFF =============\n";
  {
    she_log::logger pen;

    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::OFF);
    pen.add_output_method(console);

    using namespace she_log;
    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<log_level::DEBUG>(msg);
      pen.record<log_level::INFO>(msg);
    }
  }
  std::cout<<"========== JUST INFO ==========\n";
  {
    she_log::logger pen;

    const auto console = std::make_shared<she_log::console>();
    console->set_format(she_log::log_format::SHE_LOG);
    console->set_level(she_log::log_level::INFO);
    pen.add_output_method(console);

    using namespace she_log;
    for (int i = 0; i < 10; ++i) {
      auto msg = std::to_string(i + 1);
      pen.record<log_level::DEBUG>(msg);
      pen.record<log_level::INFO>(msg);
    }
  }


  return true;
}
