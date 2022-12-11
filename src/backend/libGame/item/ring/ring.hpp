#ifndef RING
#define RING
#include "../item.hpp"
#include <string>

using namespace std;

class Ring: public Item {
  protected:
    int life_;
    int def_;
  public:
    Ring(int l, int d, string s):
      life_(l), def_(d), Item(s) {};
    virtual string getClass() {
      return "Ring";
    }
    virtual string describe() {
      return "A regular ring...";
    };
};

#endif
