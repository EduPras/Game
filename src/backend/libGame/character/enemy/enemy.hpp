#ifndef ENEMY
#define ENEMY

#include <string>
#include "../character.hpp"

class Enemy: public Character {
private:
  float magic;
public:
  Enemy(int l): Character("Enemy "+ to_string(l), "Level "+ to_string(l)) {};
  Enemy(): Character("Enemy 0", "Level 0") {};
  void magic_attack(Character& opponent);
};
#endif
