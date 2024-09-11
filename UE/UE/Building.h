#pragma once
#include <iostream>

class Building {
private:
  int ID;
  int maxAge;
  int initialCost;
  int currAge = 0;

  void Destroy();
public:
  ~Building();
  Building();
  Building(int _ID, int _maxAge, int _initialCost);

  int getCost();
  void toAge(int year);
};