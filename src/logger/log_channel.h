#ifndef SHE_LOG_LOGGER_LOG_CHANNEL_H
#define SHE_LOG_LOGGER_LOG_CHANNEL_H

#include <condition_variable>
#include <mutex>
#include <queue>

namespace she_log {

struct log_info {
  log_level level;
  std::chrono::time_point<std::chrono::system_clock> time_point;
  std::string message;
};

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

  void process_logs(const std::function<void(log_info)>& process_func) {
    while (true) {
      std::unique_lock<std::mutex> lock(mutex);
      cv.wait(lock, [this]() { return !log_queue.empty() || stop_requested; });

      if (stop_requested && log_queue.empty())  // (1)stop (2)log_queue is empty
        break;

      T log = log_queue.front();
      log_queue.pop();
      lock.unlock();

      // process log_info
      if (process_func != nullptr) {
        process_func(log);
      }
    }
  }

  void stop() {
    stop_requested = true;
    cv.notify_one();  // 通知等待中的线程停止
  }
};

}  // namespace she_log

#endif  // SHE_LOG_LOGGER_LOG_CHANNEL_H
