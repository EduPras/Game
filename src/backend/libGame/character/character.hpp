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
    float strength_, defense_;
    Weapon *weapon_;
    string class_;
  public:
    Character (string n, string c);
    ~Character (){
      cout << "Deleting character :"<< this->name_ <<"...\n";
    }
    void attack(Character& opponent, Weapon* weapon);
    void show_status();
    void operator <<(Item* i);
    // getters
    string getName() { return this->name_; }
    float getLife() { return this->life_; }
    float getStrength() { return this->strength_; }
    float getDefense() { return this->defense_; }
    Weapon* getWeapon() { return this->weapon_;}
    // setters
    void setLife(float l){ this->life_ = l; }
    void setWeapon(Weapon * w);
};

#endif
