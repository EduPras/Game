#ifndef WEAPON
#define WEAPON

#include "../item.hpp"
#include <string>

using namespace std;

class Weapon: public Item{
protected: 
  int damage_;
  Weapon(int d, string s): Item(s), damage_(d) {};
public:
  virtual string describe() = 0;
  virtual string getClass() = 0;
  int getDamage() { return this->damage_; }
};

#endif
