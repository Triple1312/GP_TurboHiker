//
// Created by ppp on 12/22/20.
//

#ifndef GP_SRC_MODEL_TRIGGER_H_
#define GP_SRC_MODEL_TRIGGER_H_
#include <functional>

class Trigger {
 public:
  // template<class T, class S, class U>
  Trigger(std::function<void()> &action, std::function<bool()> &trigger,
          bool del = true);

  bool Done();

 private:
  std::function<void()> action_;
  std::function<bool()> trigger_;
  bool del_;
};

#endif  // GP_SRC_MODEL_TRIGGER_H_
