#pragma once
#include <iostream>

class Building {
private:
  static int ID;
  int maxAge;
  int initialCost;
  int currAge = 0;

  void Destroy();
public:
  ~Building();
  Building();
  Building(int _maxAge, int _initialCost);

  int getCost();
  void toAge(int year);
};