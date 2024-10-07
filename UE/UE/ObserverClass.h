#pragma once
#include <string>
#include "CreatureClass.h"

class Creature;

class Observer {
  static int ID;
public:
  Observer();
  virtual ~Observer();
  virtual void onNotify(const Creature& entity);
  bool operator==(const Observer& a);
};

class ObserverPrint : public Observer
{

public:
  void onNotify(const Creature& entity) final;

private:
  void printRaceName(std::string race_name);
};