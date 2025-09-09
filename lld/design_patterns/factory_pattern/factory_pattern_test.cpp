#include "factory.h"

int main() {
  ProductFactory factory;
  factory.registerProduct<ConcreteProductA>("A");
  factory.registerProduct<ConcreteProductA>("B");
  auto productA = factory.createProduct("A");
  auto productB = factory.createProduct("B");
  productA->operation();
  productA->operation();
  return 0;
}