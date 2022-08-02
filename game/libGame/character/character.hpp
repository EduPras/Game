#ifndef CHARACTER
#define CHARACTER

#include <iostream>
#include <string>
#include <vector>
#include "../item/item.hpp"
#include "../item/items.hpp"

using namespace std;
class Character {
  protected:
    string name_;
    float life_;
    int strength_, defense_;
    vector<Item*> items_;
    string class_;
  public:
    Character (string n, string c): 
      name_(n),
      life_(900),
      strength_(10),
      defense_(10),
      items_({}),
      class_(c)
    {};
    ~Character (){
      cout << "Deleting character...\n";
    }
    void attack(Character& opponent, Weapon* weapon);
    void show_status();
    void operator <<(Item* i);
    void list_items();
    // getters
    string getName() { return this->name_; }
    float getLife() { return this->life_; }
    int getStrength() { return this->strength_; }
    int getDefense() { return this->defense_; }
    // setters
    void setLife(float l){ this->life_ = l; }
};

#endif
