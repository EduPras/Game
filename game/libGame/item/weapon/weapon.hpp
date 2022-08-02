#ifndef WEAPON
#define WEAPON

#include "../item.hpp"
#include <string>

using namespace std;
// Weapon
class Weapon: public Item{
protected: 
  int damage_;
  Weapon(int d, string s): Item(s), damage_(d) {};
public:
  virtual string describe() {
    return "A regular weapon!";
  };
  virtual string getClass() {
    return "Weapon";
  };
  int getDamage() { return this->damage_; }
};

#endif
