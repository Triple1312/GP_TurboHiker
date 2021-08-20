

#ifndef GP_SRC_MODEL_CLOCK_HPP_
#define GP_SRC_MODEL_CLOCK_HPP_

#include <chrono>

class Clock {
 public:
  unsigned int GetTimeAsSeconds() {
    return std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::steady_clock::now() - begin_)
        .count();
  }

  unsigned int GetTimeAsMilliSeconds() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::steady_clock::now() - begin_)
        .count();
  }

  unsigned int GetTimeAsMicroSeconds() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::steady_clock::now() - begin_)
        .count();
  }

  void Update() {
    since_last_ = std::chrono::duration_cast<std::chrono::microseconds>(
                      std::chrono::steady_clock::now() - last_)
                      .count();
    last_ = std::chrono::steady_clock::now();
  }

  void Reset() {
    begin_ = std::chrono::steady_clock::now();
    last_ = std::chrono::steady_clock::now();
    since_last_ = 0;
  }

  static Clock *Get() {
    if (!instance_) {
      instance_ = new Clock;
    }
    return instance_;
  }

  double TimeSinceLast() const { return since_last_; }

  double GetTimeSinceLastInSeconds() const { return since_last_ / 1000000; }

  uint32_t GetTimeSinceLastInMilliSeconds() const { return since_last_ / 1000; }

 private:
  Clock() {
    begin_ = std::chrono::steady_clock::now();
    last_ = std::chrono::steady_clock::now();
    since_last_ = 0;
  }

  std::chrono::_V2::steady_clock::time_point begin_;

  float since_last_;

  std::chrono::_V2::steady_clock::time_point last_;

  static Clock *instance_;
};

class Timer {
 public:
  static Timer ConstructAsSeconds(unsigned int time) {
    return Timer(time * 1000000);
  }

  static Timer ConstructAsMicroSeconds(unsigned int time) {
    return Timer(time);
  }

  static Timer ConstructAsMilliSeconds(unsigned int time) {
    return Timer(time * 1000);
  }

  bool Complete() {
    return std::chrono::duration_cast<std::chrono::microseconds>(
               std::chrono::steady_clock::now() - begin_)
               .count() > time_;
  }

  float Percentage() {
    if (std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - begin_)
            .count() > time_) {
      return 1.f;
    } else {
      return std::chrono::duration_cast<std::chrono::microseconds>(
                 std::chrono::steady_clock::now() - begin_)
                 .count() /
             1000000.F / float(time_);
    }
  }

 private:
  unsigned int time_;

  std::chrono::_V2::steady_clock::time_point begin_;

  explicit Timer(unsigned int time) : time_(time) {
    begin_ = std::chrono::steady_clock::now();
  }
};
#endif  // GP_SRC_MODEL_CLOCK_HPP_
