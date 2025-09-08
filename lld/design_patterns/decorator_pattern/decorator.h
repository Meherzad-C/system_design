#pragma once

/*
*              +----------------------+
*              |     Component        |<-- Interface
*              | + virtual operation()|
*              +----------------------+
*                        ^
*                        |  is-a
*           +----------------------------+
*           |    ConcreteComponent       |
*           | + operation()              |
*           +----------------------------+
*                        ^
*                        |  is-a
*              +----------------------+
*              |      Decorator       |  <--- Abstract Decorator
*              | - component_         |  --> has-a Component
*              | + operation()        |
*              +----------------------+
*                        ^
*                        |  is-a
*		+------------------------------------------+
*		|         ConcreteDecoratorA/B             |
*		| + operation()                            |
*		| + (optional new methods / behaviors)     |
*		+------------------------------------------+
*                        ^
*                        |
*                    +--------+
*                    | main() |
*                    +--------+
*
*/

#include <iostream>
#include <memory>

template <typename T>
class Component {
 public:
  virtual ~Component() = default;
  virtual T operation() const = 0;
};

template <typename T>
class ConcreteComponent : public Component<T> {
 public:
  T operation() const override { return "Base"; }
};

template <typename T>
class Decorator : public Component<T> {
 protected:
  std::shared_ptr<Component<T>> component;

 public:
  explicit Decorator(std::shared_ptr<Component<T>> comp)
      : component(std::move(comp)) {}

  T operation() const override { return component->operation(); }
};

template <typename T>
class ConcreteDecoratorA : public Decorator<T> {
 public:
  explicit ConcreteDecoratorA(std::shared_ptr<Component<T>> comp)
      : Decorator(std::move(comp)) {}

  T operation() const override {
    T result = this->component->operation();
    std::cout << "Decorator A used" << std::endl;
    return result + " + A";
  }
};

template <typename T>
class ConcreteDecoratorB : public Decorator<T> {
 public:
  explicit ConcreteDecoratorB(std::shared_ptr<Component<T>> comp)
      : Decorator(std::move(comp)) {}

  T operation() const override {
    T result = this->component->operation();
    std::cout << "Decorator B used" << std::endl;
    return result + " + B";
  }
};