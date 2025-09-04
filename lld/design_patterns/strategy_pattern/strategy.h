#pragma once

/*
*      +------------------------+
*      |      Strategy          |<-- Interface
*      | + virtual execute()    |
*      +------------------------+
*           ^               ^
*           |               |
*   +---------------+   +---------------+
*   |   StrategyA   |   |   StrategyB   |
*   | + execute()   |   | + execute()   |
*   +---------------+   +---------------+
*           ^               ^
*           \               /
*            \             /
*             \           /
*              \         /
*        +------------------------+
*        |        Context         |
*        | - strategy_: Strategy  |
*        | + setStrategy()        |
*        | + executeStrategy()    |
*        +------------------------+
*                   ^
*                   |
*              +---------+
*              |  main() |
*              +---------+
*
*/

#include <iostream>
#include <memory>

class Strategy {
 public:
  Strategy() = default;
  virtual ~Strategy() = default;
  virtual std::string execute() = 0;
};

class StrategyA : public Strategy {
 public:
  std::string execute() override;
};

class StrategyB : public Strategy {
 public:
  std::string execute() override;
};

class Context {
 private:
  std::shared_ptr<Strategy> _strategy;

 public:
  explicit Context(std::shared_ptr<Strategy> strategy = nullptr);
  void setStrategy(std::shared_ptr<Strategy> strategy);
  void executeStrategy();
};