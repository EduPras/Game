#ifndef HERO_HPP
#define HERO_HPP

#include <string>
#include "../character.hpp"

class Hero: public Character {
private:
  int bençao;
public:
  Hero(string s): Character("Hero"), bençao(50) {};
  //void healing(Hero* h){}
};
#endif
