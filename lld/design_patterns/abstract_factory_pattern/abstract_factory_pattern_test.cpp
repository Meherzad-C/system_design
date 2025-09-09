#include "abstract_factory.h"

void renderUI(const GUIFactory& factory) {
  auto button = factory.createButton();
  auto checkbox = factory.createCheckbox();
  button->draw();
  checkbox->toggle();
}

int main() {
  WinFactory winFactory;
  MacFactory macFactory;

  std::cout << "Windows UI:\n";
  renderUI(winFactory);

  std::cout << "\nMac UI:\n";
  renderUI(macFactory);

  return 0;
}
