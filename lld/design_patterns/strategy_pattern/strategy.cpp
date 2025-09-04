#include "strategy.h"

std::string StrategyA::execute() {
  return "Exectue strategy A";
}

std::string StrategyB::execute() {
  return "Exectue strategy B";
}

Context::Context(std::shared_ptr<Strategy> strategy)
    : _strategy(std::move(strategy)) {}

void Context::setStrategy(std::shared_ptr<Strategy> strategy) {
  _strategy = std::move(strategy);
}

void Context::executeStrategy() {
  if (_strategy) {
    std::cout << _strategy->execute() << std::endl;
  } else {
    std::cout << "No strategy set!" << std::endl;
  }
}
