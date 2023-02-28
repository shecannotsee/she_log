//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_TEST_M4_QUEUE_TEST_H_
#define SHE_LOG_TEST_M4_QUEUE_TEST_H_

#include <chrono>
#include <thread>
#include <buffer/MessageSafeQueue.h>

namespace m4_queue_test {

int main() {
  sheLog::MessageSafeQueue message_queue;

  // 生产者线程
  std::thread producer([&message_queue]() {
    for (int i = 0; i < 10; i++) {
      std::string message = "Message " + std::to_string(i);
      message_queue.addMessage(message);
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

  return 0;
};

};// namespace m4_queue_test

#endif //SHE_LOG_TEST_M4_QUEUE_TEST_H_
