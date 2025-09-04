#include <iostream>
#include <memory>
#include "subject_observer.h"

class ConcreteObserver : public Observer {
 private:
  std::string _name;

 public:
  explicit ConcreteObserver(const std::string& name) : _name(name) {}

  void update() override {
    std::cout << "Observer [" << _name << "] " << "notified!" << std::endl;
  }
};

int main() {

  auto subject = std::make_shared<Subject>();

  auto observer1 = std::make_shared<ConcreteObserver>("A");
  auto observer2 = std::make_shared<ConcreteObserver>("B");
  auto observer3 = std::make_shared<ConcreteObserver>("C");

  subject->attach(observer1);
  subject->attach(observer2);
  subject->attach(observer3);

  std::cout << "Notifying observers..." << std::endl;
  subject->notify();

  subject->detatch(observer3);

  std::cout << "Notifying observers..." << std::endl;
  subject->notify();

  return 0;
}