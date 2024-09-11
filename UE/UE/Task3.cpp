#include <iostream>
#include "Building.h"

int main() {
  Building* A = new Building(1, 10, 4);

  A->toAge(5);

  std::cout << A->getCost() << "\n";

  A->toAge(5);

  std::cout << A->getCost();
}