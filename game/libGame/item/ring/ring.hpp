#ifndef RING
#define RING
#include "../item.hpp"
#include <string>

using namespace std;

class Ring: public Item {
  protected:
    int glow_;
  public:
    Ring(int g, string s):
      glow_(g), Item(s) {};
    virtual string getClass() {
      return "Ring";
    }
    virtual string describe() {
      return "A regular ring...";
    };
};

#endif
