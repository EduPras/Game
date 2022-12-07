#ifndef SHADOW 
#define SHADOW

#include "../ring.hpp"

class Shadow: public Ring {
  private:
    int spell_;
  public:
    Shadow(int g, int s, string ss): 
      spell_(s), Ring(g, ss){};
    virtual string getClass(){
      return "Ring Shadow";
    }
    virtual string describe();
};
#endif
