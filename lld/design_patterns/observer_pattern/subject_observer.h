#pragma once

#include <vector>
#include <memory>
#include <algorithm>

class Observer;

class Subject {
 private:
  std::vector<std::shared_ptr<Observer>> _observers;

 public:
  Subject() = default;
  ~Subject() = default;

  void attach(std::shared_ptr<Observer> observer);

  void detatch(std::shared_ptr<Observer> observer);

  void notify();
};

class Observer {
 public:
  Observer() = default;

  virtual ~Observer() = default;

  virtual void update() = 0;
};