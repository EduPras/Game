#ifndef ENEMY
#define ENEMY

#include <string>
#include "../character.hpp"

class Enemy: public Character {
private:
  float magic;
public:
  Enemy(string s): Character(s, "Enemy") {};
  void magic_attack(Character& opponent);
};
#endif
