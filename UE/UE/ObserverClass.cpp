#include "ObserverClass.h"
#include <iostream>

int Observer::ID = 0;

Observer::Observer() {
  ID++;
};
Observer::~Observer() {};
void Observer::onNotify(const Creature& entity) {
  std::cout << "Just Observer\n";
};

bool Observer::operator==(const Observer& a) {
  if (this->ID == a.ID)return true;
    return false;
  }

void ObserverPrint::onNotify(const Creature& entity)
{
  std::cout << "Notification received!\n";
  this->printRaceName(entity.GetName());
  entity.printName();
}

void ObserverPrint::printRaceName(std::string race_name)
{
  std::cout << race_name << "\n";
}
