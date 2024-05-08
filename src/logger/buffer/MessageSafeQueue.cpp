//
// Created by shecannotsee on 2023/2/28.
//

#include "MessageSafeQueue.h"
#include <common/exception/exception.h>

void she_log::MessageSafeQueue::addMessage(const std::string &message) {
  std::unique_lock<std::mutex> lock(mutex_);
  queue_.push(message);
  lock.unlock();
  condition_variable_.notify_one(); // 通知等待的线程有新消息
};


std::string she_log::MessageSafeQueue::getMessage() {
  std::unique_lock<std::mutex> lock(mutex_);
  while (queue_.empty()) {
    condition_variable_.wait(lock);
  }
  std::string message = std::string(queue_.front());
  queue_.pop();
  return message;
};

