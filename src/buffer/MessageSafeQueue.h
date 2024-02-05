//
// Created by shecannotsee on 2023/2/28.
//

#ifndef SHE_LOG_SRC_BUFFER_MESSAGESAFEQUEUE_H_
#define SHE_LOG_SRC_BUFFER_MESSAGESAFEQUEUE_H_

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace she_log {

class MessageSafeQueue {
 public:
  MessageSafeQueue() = default;
  ~MessageSafeQueue() = default;
  // disable copy
  MessageSafeQueue(const MessageSafeQueue& x) = delete;
  MessageSafeQueue& operator=(const MessageSafeQueue& x) = delete;
  // disable move
  MessageSafeQueue(MessageSafeQueue&&) = delete;
  MessageSafeQueue& operator=(MessageSafeQueue&& x) = delete;

 private:
  std::queue<std::string> queue_;
  std::mutex mutex_;
  std::condition_variable condition_variable_;
 public:
  void addMessage(const std::string& message);

  std::string getMessage();

};// class MessageSafeQueue

};// namespace sheLog

#endif //SHE_LOG_SRC_BUFFER_MESSAGESAFEQUEUE_H_
