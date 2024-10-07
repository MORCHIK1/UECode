#include "CreatureClass.h"

std::string Creature::raceName = "Creature";

std::string Creature::GetName() const {
    return raceName;
};

std::string Human::raceName = "Human";

void Human::printName() const {
  std::cout << "My race is " << raceName;
};
std::string Human::GetName() const {
  return raceName;
};


std::string Elf::raceName = "Elf";

void Elf::printName() const {
  std::cout << "My race is " << raceName;
};
std::string Elf::GetName() const {
  return raceName;
};

std::string Goblin::raceName = "Goblin";

void Goblin::printName() const {
  std::cout << "My race is " << raceName;
};
std::string Goblin::GetName() const {
    return raceName;
};