#ifndef ROCK
#define ROCK

#include "../ring.hpp"

class Rock: public Ring {
  private:
    int life_;
  public:
   /* Rock(int g, int l,string s): 
      life_(l), Ring(g, s){};
    virtual string getClass(){
      return "Ring Rock";
    } 
    virtual string describe();
    */
};
#endif
