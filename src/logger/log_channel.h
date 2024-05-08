#ifndef SHE_LOG_LOGGER_LOG_CHANNEL_H
#define SHE_LOG_LOGGER_LOG_CHANNEL_H

#include <condition_variable>
#include <mutex>
#include <queue>

namespace she_log {

/**
 * @brief
 * @tparam T queue data structure
 */
template <typename T>
class log_channel {
 public:
  log_channel() = default;

 private:
  std::queue<T> log_queue;
  std::mutex mutex;
  std::condition_variable cv;
  bool stop_requested = false;

 public:
  void push_log(const T& log) {
    {
      std::lock_guard<std::mutex> lock(mutex);
      log_queue.push(log);
    }
    cv.notify_one();  // 通知等待中的线程有新的日志可用
  }

  void process_logs() {
    while (true) {
      std::unique_lock<std::mutex> lock(mutex);
      cv.wait(lock, [this]() { return !log_queue.empty() || stop_requested; });

      if (stop_requested && log_queue.empty())  // (1)stop (2)log_queue is empty
        break;

      T log = log_queue.front();
      log_queue.pop();
      lock.unlock();

      // process log_info
      printf("Processed log:%s\n", log.message.c_str());
    }
  }

  void stop() {
    stop_requested = true;
    cv.notify_one();  // 通知等待中的线程停止
  }
};

}  // namespace she_log

#endif  // SHE_LOG_LOGGER_LOG_CHANNEL_H
