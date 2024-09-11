#include <iostream>
#include <string>
#include <vector>
#include <limits>

enum Result {
  ClanZeroWon,
  ClanOneWon,
  DRAW
};

class Player {
private:
  int clanID;
  float health;
  float damage;
  std::string name;
public:

  Player(std::string _name, int _clanID, float _health, float _damage) : name(_name), clanID(_clanID), health(_health), damage(_damage)
  {};
  ~Player() { std::cout << "\nPLAYER DELETED!\n"; };


  static void findAndDelete(std::vector<Player*>& LobbyVec, std::string& namePl, int ID) {
    if (LobbyVec.size() == 0) {
      std::cout << "В лоббі не залишилось персонажів! \n";
      return;
    }

    for (int i = 0; i < LobbyVec.size(); ++i) {
      if (LobbyVec[i]->name == namePl && LobbyVec[i]->clanID == ID) {
        LobbyVec.erase(LobbyVec.begin() + i);
        std::cout << "Персонаж знайдений та видалений!\n";
      }
    }

    for (auto a : LobbyVec) std::cout << a->name;
  }

  static Result startFight(std::vector<Player*>& LobbyVec) {
    float HPzero = 0, DMGzero = 0;
    float HPfirst = 0, DMGfirst = 0;

    for (auto PlayerInfo : LobbyVec) {
      if (PlayerInfo->clanID == 0) {
        HPzero += PlayerInfo->health;
        DMGzero += PlayerInfo->damage;
      }
      else {
        HPfirst += PlayerInfo->health;
        DMGfirst += PlayerInfo->damage;
      }
    }

    float HPremained_zero_clan = HPzero - DMGfirst;
    float HPremained_first_clan = HPfirst - DMGzero;

    std::cout << "Zero clan HP: " << HPzero << " Zero clan DMG: " << DMGzero << "\n";
    std::cout << "First clan HP: " << HPfirst << " First clan DMG: " << DMGfirst << "\n";


    if (HPremained_first_clan <= 0 && HPremained_zero_clan <= 0) return DRAW;
    else if (HPremained_first_clan <= 0) return ClanZeroWon;
    else return ClanOneWon;
  }

};


int tmain() {
  Player* A = new Player("Andrii", 0, 100.0, 50.0);
  Player* B = new Player("Bogdan", 1, 50.0, 10.0);

  std::vector<Player*> Lobby;
  Lobby.push_back(A);
  Lobby.push_back(B);
  while (true) {
    int Command;

    std::cout << "Введіть команду(0 - добавити гравця, 1 - вилучити гравця з бою, 2 - провести бій) :\n";
    while (!(std::cin >> Command)) {
      std::cout << "Invalid input. Please enter an integer: ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (Command) {
    case(0):
    {
      std::string name;
      float hp, dmg;
      int clanID;
      std::cout << "Введіть спочатку ім'я гравця потім його номер клану потім кількість його здоров'я та кількість ушкоджень, які він наносить: \n";
      std::cin >> name >> clanID >> hp >> dmg;
      std::cout << "\n";
      Player* C = new Player(name, clanID, hp, dmg);
      Lobby.push_back(C);

      break;
    }
    case(1):
    {
      std::string name;
      int clanID;
      std::cout << "Введіть ім'я та номер клану гравця, якого хочете вилучити з лоббі: \n";
      std::cin >> name >> clanID;
      Player::findAndDelete(Lobby, name, clanID);
      break;
    }
    case(2):
    {
      std::cout << "Характеристика кланів: \n";
      Result res = Player::startFight(Lobby);
      if (res == ClanOneWon) {
        std::cout << "Перший клан переміг!\n";
      }
      else if (res == ClanZeroWon) {
        std::cout << "Нульовий клан переміг!\n";
      }
      else {
        std::cout << "Нічия!\n";
      }
      std::cout << "Бажаєте продовжити гру? (0 - ні, 1 - так)";
      bool endGame;
      std::cin >> endGame;
      if (!endGame) return 0;
      break;
    }
    default:
      std::cout << "Ви ввели номер не існуючої команди!\n";
      break;
    }
  }
  return 0;
}