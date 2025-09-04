#include <iostream>
#include <memory>
#include "strategy.h"

int main() {
  Context context;

  // Use strategy A
  auto strategyA = std::make_shared<StrategyA>();
  context.setStrategy(strategyA);
  context.executeStrategy();

  // Switch to strategy B
  auto strategyB = std::make_shared<StrategyB>();
  context.setStrategy(strategyB);
  context.executeStrategy();

  return 0;
}