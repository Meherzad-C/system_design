#include <iostream>
#include <memory>
#include "decorator.h"

int main() {
  using T = std::string;
  auto base = std::make_shared<ConcreteComponent<T>>();
  auto decorateA = std::make_shared<ConcreteDecoratorA<T>>(base);
  auto decorateB = std::make_shared<ConcreteDecoratorB<T>>(decorateA);

  T result = decorateB->operation();
  std::cout << "Final result " << result << std::endl;
  return 0;
}