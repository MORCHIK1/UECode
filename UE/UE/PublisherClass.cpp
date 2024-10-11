#include "Publisher.h"
#include <iostream>

void Publisher::AddObserver(Observer* observer_) {
  MyObservers.push_back(observer_);
}

void Publisher::RemoveObserver(const Observer* _observer) {
  auto it = find(MyObservers.begin(), MyObservers.end(), _observer);
  MyObservers.erase(it);
}
void Publisher::notify(const Creature& entity) {
  for (auto& it : MyObservers) {
    it->onNotify(entity);
  }
  std::cout << "Observers were notified!\n";
  number_of_creatures++;
};
