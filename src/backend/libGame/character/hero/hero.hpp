#ifndef HERO_HPP
#define HERO_HPP

#include <string>
#include "../character.hpp"

class Hero: public Character {
private:
  float critic;
public:
  Hero(string s): Character(s, "Hero") {};
};
#endif
