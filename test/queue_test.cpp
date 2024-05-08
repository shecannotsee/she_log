#include <she_test.h>

#include <chrono>
#include <thread>
#include <logger/buffer/MessageSafeQueue.h>


SHE_TEST(unit_test, queue_test) {
  she_log::MessageSafeQueue message_queue;

  // 生产者线程
  std::thread producer([&message_queue]() {
    for (int i = 0; i < 10; i++) {
      std::string message = "Message " + std::to_string(i);
      message_queue.addMessage(message);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  });

  // 消费者线程
  std::thread consumer([&message_queue]() {
    for (int i = 0; i < 10; i++) {
      std::string message = message_queue.getMessage();
      std::cout << "Received message:[" << message << "]\n";
    }
  });

  producer.join();
  consumer.join();

  return true;
}
