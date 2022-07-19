#ifndef ITEM
#define ITEM

#include <string>

using namespace std;

class Item {
protected:
  string name;
public:
  virtual string describe();
  virtual string getClass ();
  string getName();
};

class Weapon: public Item{
protected: 
  int damage;
public:
  string getClass();
};

class Sword: public Weapon {
  float critic;
public:
  Sword (int d, float c, string s) ;
  string describe();
  string getClass();
};
#endif