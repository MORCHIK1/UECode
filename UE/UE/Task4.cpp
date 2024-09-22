#include <iostream>
#include <memory>
#include <string>

class Weapon {
private:
  std::string weaponName = "";
  float damage = 0.0;

public:
  ~Weapon() {
    std::cout << "\nWeapon destructor called\n";
  }
  virtual float GetDamage() = 0;
  virtual std::string GetName() = 0;
};

class Sword : public Weapon{
  float damage = 15.0;
  std::string weaponName = "Sword\n";
public:
  virtual float GetDamage() override {
    return damage;
  }
  virtual std::string GetName() override {
    return weaponName;
  }
};

class Rifle : public Weapon {
  float damage = 50.0;
  std::string weaponName = "Rifle\n";
public:
  virtual float GetDamage() override {
    return damage;
  }
  virtual std::string GetName() override {
    return weaponName;
  }
};

class RocketLauncher : public Weapon {
  float damage = 70.0;
  std::string weaponName = "RocketLauncher\n";
public:
  virtual float GetDamage() override {
    return damage;
  }
  virtual std::string GetName() override {
    return weaponName;
  }
};

class Character {
private:
  std::unique_ptr<Weapon> currWeapon;
public:
  ~Character() {
    std::cout << "\nCharacter destructor called\n";
  }

  void SetWeapon(std::unique_ptr<Weapon> weapon) {
    currWeapon = std::move(weapon);
  }
  Weapon* GetWeapon() const {
    return currWeapon.get();
  }
};

int main() {
  Character Aurora;
  std::unique_ptr <Rifle> forAurora = std::make_unique<Rifle>();

  std::cout << forAurora->GetName();
  std::cout << forAurora->GetDamage();

  Aurora.SetWeapon(std::move(forAurora));
  std::cout << Aurora.GetWeapon()->GetName();

  Aurora.SetWeapon(std::make_unique<RocketLauncher>());

  std::cout<<Aurora.GetWeapon()->GetDamage();
}