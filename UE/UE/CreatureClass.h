#pragma once
#include <string>
#include <vector>
#include <iostream>

class Creature {
private:
  static std::string raceName;
public:
  virtual std::string GetName() const;
  virtual void printName() const = 0;
};

class Human : public Creature {
private:
  static std::string raceName;
public:
  void printName() const final;
  std::string GetName() const final;
};

class Elf : public Creature {
private:
  static std::string raceName;
public:
  void printName() const final;
  std::string GetName() const final;
};

class Goblin : public Creature {
private:
  static std::string raceName;
public:
  void printName() const final;
  std::string GetName() const final;
};