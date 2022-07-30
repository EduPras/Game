#ifndef ROCK
#define ROCK

#include "../ring.hpp"

class Rock: public Ring {
  private:
    int life_;
  public:
    Rock(string s, int g, int l): 
      life_(l), Ring(g, s){};
    virtual string getClass(){
      return "Ring Rock";
    }
    virtual string describe();
};
#endif
