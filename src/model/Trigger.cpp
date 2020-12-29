//
// Created by ppp on 12/22/20.
//

#include "Trigger.h"
Trigger::Trigger(std::function<void()> &action, std::function<bool()> &trigger, bool del) {
  this->action_ = action;
  this->trigger_ = trigger;
  this->del_ = del;
}
bool Trigger::Done() {
  if( trigger_) {
    action_;
    return del_;
  }
  return false;
}
