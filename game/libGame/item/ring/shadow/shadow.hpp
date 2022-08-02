#ifndef SHADOW 
#define SHADOW

#include "../ring.hpp"

class Shadow: public Ring {
  private:
    int spell_;
  public:
    Shadow(string ss, int g, int s): 
      spell_(s), Ring(g, ss){};
    virtual string getClass(){
      return "Ring Shadow";
    }
    virtual string describe();
};
#endif
