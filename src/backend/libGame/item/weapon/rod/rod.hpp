#ifndef ROD
#define ROD

#include <string>
#include "../weapon.hpp"
// Rod
class Rod: public Weapon {
protected:
  float spell_damage;
public:
  Rod (int d, float s, string ss):
   spell_damage(s), Weapon(d, ss) {};
  virtual string describe();  
  string getClass() {
    return "Rod";
  };
};

#endif
