#pragma once

/*
*                        +---------------------------------+
*                        |            IProduct             |  <--- Interface
*                        | + virtual operation() const = 0 |
*                        +---------------------------------+
*                             ^                     ^
*                             | is-a                | is-a
*          +--------------------------+       +--------------------------+
*          |     ConcreteProductA     |       |     ConcreteProductB     |
*          | + operation() const      |       | + operation() const      |
*          +--------------------------+       +--------------------------+
*                             ^                          ^
*                             |                          |
*                             +-----------+--------------+
*                                         |
*                           +------------------------------+
*                           |        ProductFactory        |  <--- Generic Factory
*                           | - creators_ : map<string, Fn>|  --> key-to-creator mapping
*                           | + registerProduct<T>()       |  --> registers a type
*                           | + createProduct(key)         |  --> creates instance
*                           +------------------------------+
*                                            ^
*                                            |
*                                      +----------+
*                                      |  main()  |
*                                      +----------+
*                                            |
*                    -----------------------------------------------------
*                    |                       |                           |
*              registerProduct<A>("A")   registerProduct<B>("B")   createProduct("A"/"B")
*                    |                       |                           |
*                  (setup)                (setup)                      returns A or B
*                                                                     calls operation()
*
*/

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

// ---Product Interface---
class IProduct {
 public:
  virtual void operation() const = 0;
  virtual ~IProduct() = default;
};

// ---Concrete Products---
class ConcreteProductA : public IProduct {
 public:
  void operation() const override {
    std::cout << "ConcreteProductA operation()\n";
  }
};

class ConcreteProductB : public IProduct {
 public:
  void operation() const override {
    std::cout << "ConcreteProductB operation()\n";
  }
};

// ---Generic Factory---
class ProductFactory {
 private:
  using Creator = std::function<std::unique_ptr<IProduct>()>;
  std::unordered_map<std::string, Creator> creators_;

 public:
  template <typename T>
  void registerProduct(const std::string& key) {
    creators_[key] = []() {
      return std::make_unique<T>();
    };
  }

  std::unique_ptr<IProduct> createProduct(const std::string& key) const {
    auto it = creators_.find(key);
    if (it != creators_.end()) {
      return (it->second)();
    }
    throw std::runtime_error("Unknown product key " + key);
  }
};