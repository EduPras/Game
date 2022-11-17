#ifndef ENEMY
#define ENEMY

#include <string>
#include "../character.hpp"

class Enemy: public Character {
private:
  float magic;
public:
  Enemy(int l): Character("Enemy", "Level "+ to_string(l)) {};
  Enemy(): Character("Enemy", "Level 0") {};
  void magic_attack(Character& opponent);
};
#endif
