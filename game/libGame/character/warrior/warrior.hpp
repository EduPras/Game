#ifndef WARRIOR
#define WARRIOR

#include <string>
#include "../character.hpp"

class Warrior: public Character {
private:
  float critic;
public:
  Warrior(string s): Character(s, "Warrior") {};
  void increase_defense();
};
#endif
