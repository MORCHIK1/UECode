#include "ObserverClass.h"
#include "CreatureClass.h"
#include "Publisher.h"

int main() {
  ObserverPrint* ab = new ObserverPrint;
  Human a;
  Publisher res;
  ab->onNotify(a);
  res.AddObserver(ab);
  res.notify(a);
  std::string answ = a.GetName();
  std::cout << answ;
  a.printName();
  delete ab;
}