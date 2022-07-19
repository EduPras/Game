#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>
#include <vector>
#include "../item/item.hpp"

using namespace std;
class Character {
  protected:
    string name;
    float life;
    int strength, defense;
    vector<Item*> items;
  public:
    Character (string n);
    // virtual void attack();
    void pick(Item* i);
    void list_items();
};

#endif