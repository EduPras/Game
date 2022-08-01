#ifndef WIZARD
#define WIZARD

#include <string>
#include "../character.hpp"

class Wizard: public Character {
private:
  float magic;
public:
  Wizard(string s): Character(s, "Wizard") {};
  void magic_attack(Character& opponent);
};
#endif
