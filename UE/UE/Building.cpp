#include <iostream>
#include "Building.h"

int Building::ID = 0;

Building::Building() {
  ID++;
};

Building::~Building() {
  std::cout << "\nObject destroyed!\n";
}

Building::Building(int _maxAge, int _initialCost) : m_ID(ID), maxAge(_maxAge), initialCost(_initialCost)
{
  ID++;
};

void Building::Destroy() {
    std::cout << "Будівля з цим айді була видалена:" << m_ID << "\n";
}

int Building::getCost() {
    if (currAge == 0) return initialCost;
    if (currAge == maxAge) return 0;

    int divisorForcost = maxAge / currAge;
    if (divisorForcost != 0) {
      int costForThisBuilding = initialCost / divisorForcost;
      return costForThisBuilding;
    }
    else {
      std::cout << "Current age is bigger than max age!";
      return -1;
    }
}

void Building::toAge(int year) {
  currAge += year;
  if (currAge > maxAge) {
    Destroy();
  }
}