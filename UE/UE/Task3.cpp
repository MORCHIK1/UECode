#include <iostream>
#include "Building.h"

int tttmain() {
  Building* A = new Building(10, 4);

  A->toAge(5);

  std::cout << A->getCost() << "\n";

  A->toAge(15);

  std::cout << A->getCost();

  Building* B = new Building(7, 4);

  B->toAge(8);

  //std::cout << B->getCost() << "\n";
  return 0;
}