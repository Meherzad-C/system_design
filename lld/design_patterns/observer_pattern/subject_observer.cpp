#include "subject_observer.h"

void Subject::attach(std::shared_ptr<Observer> observer) {
  _observers.push_back(observer);
}

void Subject::detatch(std::shared_ptr<Observer> observer) {
  _observers.erase(std::remove(_observers.begin(), _observers.end(), observer),
                   _observers.end());
}

void Subject::notify() {
  for (const auto& observer : _observers) {
    if (observer)
      observer->update();
  }
}
