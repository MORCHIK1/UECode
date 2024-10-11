#pragma once
#include <vector>
#include "ObserverClass.h"

class Publisher {
private:
  std::vector<Observer*> MyObservers;
  int number_of_creatures;
public:
  void AddObserver(Observer* observer_);
  void RemoveObserver(const Observer* _observer);
  void notify(const Creature& entity);
};
