#pragma once

/*
*                       +----------------------+
*                       |      IButton         |<-- Interface
*                       | + virtual draw()     |
*                       +----------------------+
*                              ^       ^
*                              |       |
*              +----------------+     +----------------+
*              |   WinButton    |     |   MacButton     |
*              | + draw()       |     | + draw()        |
*              +----------------+     +----------------+
*
*                       +----------------------+
*                       |     ICheckbox        |<-- Interface
*                       | + virtual toggle()   |
*                       +----------------------+
*                              ^       ^
*                              |       |
*          +---------------------+   +----------------------+
*          |   WinCheckbox       |   |    MacCheckbox       |
*          | + toggle()          |   | + toggle()           |
*          +---------------------+   +----------------------+
*
*                    +------------------------------+
*                    |         GUIFactory           |<-- Abstract Factory
*                    | + createButton()             |
*                    | + createCheckbox()           |
*                    +------------------------------+
*                           ^              ^
*                           |              |
*       +------------------------+   +------------------------+
*       |       WinFactory       |   |       MacFactory       |
*       | + createButton()       |   | + createButton()       |
*       | + createCheckbox()     |   | + createCheckbox()     |
*       +------------------------+   +------------------------+
*                           ^              ^
*                           |              |
*                      +----------------------+
*                      |        main()        |
*                      +----------------------+
*                              |      |
*                              |  factory = new MacFactory / WinFactory
*                              |  button = factory->createButton()
*                              |  checkbox = factory->createCheckbox()
*                              |  button->draw()
*                              |  checkbox->toggle()
*
*/

#include <iostream>
#include <memory>
#include <string>

// ---- Abstract Product Interfaces ----
class IButton {
 public:
  virtual void draw() const = 0;
  virtual ~IButton() = default;
};

class ICheckbox {
 public:
  virtual void toggle() const = 0;
  virtual ~ICheckbox() = default;
};

// ---- Concrete Products ----
class WinButton : public IButton {
 public:
  void draw() const override { std::cout << "Drawing Windows Button\n"; }
};

class WinCheckbox : public ICheckbox {
 public:
  void toggle() const override { std::cout << "Toggling Windows Checkbox\n"; }
};

class MacButton : public IButton {
 public:
  void draw() const override { std::cout << "Drawing Mac Button\n"; }
};

class MacCheckbox : public ICheckbox {
 public:
  void toggle() const override { std::cout << "Toggling Mac Checkbox\n"; }
};

// ---- Abstract Factory Interface ----
class GUIFactory {
 public:
  virtual std::unique_ptr<IButton> createButton() const = 0;
  virtual std::unique_ptr<ICheckbox> createCheckbox() const = 0;
  virtual ~GUIFactory() = default;
};

// ---- Concrete Factories ----
class WinFactory : public GUIFactory {
 public:
  std::unique_ptr<IButton> createButton() const override {
    return std::make_unique<WinButton>();
  }

  std::unique_ptr<ICheckbox> createCheckbox() const override {
    return std::make_unique<WinCheckbox>();
  }
};

class MacFactory : public GUIFactory {
 public:
  std::unique_ptr<IButton> createButton() const override {
    return std::make_unique<MacButton>();
  }

  std::unique_ptr<ICheckbox> createCheckbox() const override {
    return std::make_unique<MacCheckbox>();
  }
};
