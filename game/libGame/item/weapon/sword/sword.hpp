#ifndef SWORD
#define SWORD

#include "../weapon.hpp"
#include <string>

// Sword
class Sword: public Weapon {
  float critic_;
public:
  Sword (int d, float c, string s):
    critic_(c), Weapon(d, s) {};
  virtual string describe();
  string getClass() {
    return "Sword";
  }
};

#endif
