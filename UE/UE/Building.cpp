#include <iostream>
#include "Building.h"

Building::Building() = default;

Building::~Building() {
  std::cout << "Object destroyed!";
}

Building::Building(int _ID, int _maxAge, int _initialCost) : ID(_ID), maxAge(_maxAge), initialCost(_initialCost)
{};

void Building::Destroy() {
    std::cout << "Будівля з цим айді була видалена:" << ID << "\n";
}

int Building::getCost() {
    if (currAge == 0) return initialCost;
    if (currAge == maxAge) return 0;

    int divisorForcost = maxAge / currAge;
    int costForThisBuilding = initialCost / divisorForcost;
    return costForThisBuilding;
}

void Building::toAge(int year) {
  currAge += year;
  if (currAge > maxAge) {
    Destroy();
    //delete this;
    //this->~Building();
  }
}